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
        struct Task *next;

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
        Task current_task;
        string status;
        int transaction_time;

        bool isFree()
        {
            if(status = "Free")
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
            transaction_time = current_task.transaction_time;
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

        void setcurrentTask(Task task)
        {
            current_task = task;
        }

        const int getcurrentTaskNumber()
        {
            return current_task.task_number;
        }

        const int getCurrentTaskArrivalTime()
        {
            return current_task.arrival_time;
        }

        const int getCurrentTaskWaitingTime()
        {
            return current_task.waiting_time;
        }

        const int getCurrentTaskTransactionTime()
        {
            return current_task.transaction_time;
        }

        Server()
        {
            status = "Free";
        }
};

class serverList
{
    public:
        int numOfServers;
        Server **serverList;


};

class taskQueue
{
    public:
        struct Task *head;


};