#include <bits/stdc++.h>

using namespace std;


int main()
{
    vector<int> work_time = {45, 16, 5, 29, 33, 25, 21};
    int n = work_time.size();

    int start_time=0, finish_time=0, cumul_time=0, break_flag=0;
    int num_of_jobs = 57;

    int temp = 0;
    cout<<"Document no.(i) \t Start_time(tb) \t Work_Time(tw) \t Finish_Time(tf) \t Cumul_Time(tc) \t Break_flag(F) \t No. of jobs(N)."<<endl;
    for(int i=0;i<n; i++)
    {
        finish_time = work_time[i] + start_time;
        cumul_time += work_time[i];
        if(cumul_time > 60)
            break_flag = 1;
        else
            break_flag = 0;

        cout<<i<<" \t "<<start_time<<" \t "<<work_time[i]<<" \t "<<finish_time<<" \t "<<cumul_time<<" \t "<<break_flag<<" \t "<<num_of_jobs<<endl;
        num_of_jobs--;

        if(cumul_time > 60)
        {
            cumul_time = 0;
            finish_time += 5;
        }
        start_time = finish_time;
    }


    return 0;
}

