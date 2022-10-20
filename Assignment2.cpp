#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>

using namespace std;

class Task 
{
    public:
        int task_number;
        int arrival_time;
        int waiting_time;
        int transaction_time;
        Task *next;

        void setTaskInfo(int tn, int aTime, int wTime, int tTime)
        {
            task_number = tn;
            arrival_time = aTime;
            waiting_time =  wTime;
            transaction_time = tTime;
        }

        void setWaitingTime(int wTime)
        {
            waiting_time = wTime;
        }

        int getWaitingTime()
        {
            return waiting_time;
        }

        int getArrivalTime()
        {
            return arrival_time;
        }

        int getTransactionTime()
        {
            return transaction_time;
        }

        int getTaskNumber()
        {
            return task_number;
        }

        void incrementWaitingTime()
        {
            waiting_time++;
        }

        Task(int tn, int aTime, int wTime, int tTime) 
        {
            task_number = tn;
            arrival_time = aTime;
            waiting_time = wTime;
            transaction_time = tTime;
        }
};

class Server 
{
    public:
        Task *current_task;
        string status;
        int transaction_time;

        bool isFree()
        {
            if(status == "Free")
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        void setBusy()
        {
            status = "Busy";
        }

        void setFree()
        {
            status = "Free";
        }

        void setTransactionTime()
        {
            transaction_time = current_task->transaction_time;
        }

        const int getRemainingTransactionTime()
        {
            if(transaction_time == 0)
            {
                status = "Free";
            }
            return transaction_time;
        }

        void decreaseTransactionTime()
        {
            transaction_time--;
        }

        void setCurrentTask(Task *task)
        {
            current_task = task;
            setTransactionTime();
        }

        const int getCurrentTaskNumber()
        {
            return current_task->task_number;
        }

        const int getCurrentTaskArrivalTime()
        {
            return current_task->arrival_time;
        }

        const int getCurrentTaskWaitingTime()
        {
            return current_task->waiting_time;
        }

        const int getCurrentTaskTransactionTime()
        {
            return current_task->transaction_time;
        }

        Server()
        {
            status = "Free";
        }
};

class ServerList{
    public:
    
        Server **servers;
        int numOfServers;
        // Server servers[numOfServers]={}

        const int getFreeServerID()
        {
            for(int i=0;i<numOfServers;i++)
            {
                if(servers[i]->isFree())
                {
                    return i;
                }
            }
            return -1;
        }

        const int getNumberOfBusyServers()
        {
            int count = 0;
            for(int i=0;i<numOfServers;i++)
            {
                if(!servers[i]->isFree())
                {
                    count++;
                }
            }
            return count;
        }

        void setServerBusy(int serverIndex,Task *task)
        {
            servers[serverIndex]->setCurrentTask(task);
        }

        void updateServers()
        {
            for(int i=0;i<numOfServers;i++)
            {
                servers[i]->decreaseTransactionTime();
            }
        }

        ServerList(int serverCount) 
        {
            numOfServers=serverCount;
            servers=new Server*[serverCount];
            for(int i=0;i<serverCount;i++)
            {
                servers[i]=new Server();
            }
        }
};

class taskQueue
{
    public:
        Task *head = new Task(-1,-1,-1,-1);

        const bool isEmptyQueue()
        {
            if(head->next == NULL)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

        const bool isFullQueue()
        {
            return false;
        }

        void initializeQueue()
        {

        }

        Task* front()
        {
            Task *cycle = head;
            while(cycle->next != NULL)
            {
                cycle = cycle->next;
            }
            return cycle;
        }

        Task* back()
        {
            return head->next;
        }

        void push(Task *task)
        {
            task->next = head->next;
            head->next = task;
        }

        void pop()
        {
            Task *cycle = head;
            Task *nextCycle = head->next;
            if(nextCycle->next == NULL)
            {
                free(nextCycle);
                head->next = NULL;
            }
            else
            {
                while(nextCycle->next != NULL)
                {
                    cycle = nextCycle;
                    nextCycle = nextCycle->next;
                }
                free(nextCycle);
                cycle->next = NULL;
            }
        }

        void updateWaitTime()
        {
            if(head->next != NULL)
            {
                Task *cycle = head->next;
                while(cycle->next != NULL)
                {
                    cycle->incrementWaitingTime();
                    cycle = cycle->next;
                }
                cycle->incrementWaitingTime();
            }
        }
};

int main()
{
	int nus, nut, tTimeL, tTimeU, aTimeRate, simTime;

	taskQueue tQueue;
	
	cout << "Welcome to the tasks' simulator\n\n";

	cout << "Enter number of servers:";
	cin >> nus;
	ServerList sList(nus);
	
	cout << "Enter number of tasks:";
	cin >> nut;

	cout << "For transaction time, enter the range's lower value:";
	cin >> tTimeL;

	cout << "For transaction time, enter the range's upper value:";
	cin >> tTimeU;

	int oldRange = (RAND_MAX - 0);
	int newRange = (tTimeU - tTimeL);

	cout << "Enter task's arrival time rate:";
	cin >> aTimeRate;

	cout << "Enter total time of simulation:";
	cin >> simTime;

	srand(10);
	int taskNu = 1;

    for (int tCo = 1; tCo <= simTime; tCo++) {
		cout << "Time: " << tCo << endl;
		// 1- Update all servers transaction time (decrement by 1)
	 	sList.updateServers();
	    // 2- Update waiting time (increment by 1) of all tasks in the queue
	 	tQueue.updateWaitTime();
	 	// 3- Check if it is time for arrival of tasks
		if (tCo % aTimeRate == 0) {
			// Generate random transaction time
			int r = rand();
			r = (((r-0) * newRange) / oldRange) + tTimeL;
			// Create a new task
			Task *t = new Task(taskNu,tCo, 0, r);
			tQueue.push(t);
			cout << "New task " << taskNu << " arrived at time " << tCo << " with transaction time of " << r << "\n";
            taskNu++;
		}
		// 4- Check if a server is free and tasks' queue is non empty to push a task
		int sID = sList.getFreeServerID();
		if (sID != -1) {
			if (tQueue.isEmptyQueue() == false) {
				Task *t = tQueue.front();
				sList.setServerBusy(sID, t);
				tQueue.pop();
				cout << "Task " << t->getTaskNumber() << " is admitted to server " << sID << "\n";
			}
		}
	}

    return 0;
}