/*  
Please write complete compilable code.  
Read input from standard input (STDIN) and print output to standard output(STDOUT).  
For more details, please check http://www.interviewstreet.com/recruit/challenges/faq/view#stdio  
*/  
#include <iostream>  
using namespace std;  

int start[9];  
int last[9];  
int pegs[6];  
int steps[9][2];  
int minSteps = 7;  
int optimSteps[9][2];  
int N = -1;  
int K = -1;  
int MAX = 100;  

int oldi;  
int oldj;  
int old;  

void print()  
{  
    cout << minSteps << endl;  
    for(int i = 1; i <= minSteps; ++i)  
    {  
        cout << optimSteps[i][0] << " " << optimSteps[i][1] << endl;  
    }  
}  

void initPeg()  
{  
    printf("beginning init peg\n");
    for(int i = 1; i <= K; ++i)  
    {  
        pegs[i] = MAX;  
        // printf("pegs[%d] = %d\n", i, pegs[i]);
        for(int j = 1; j <= N; ++j)  
            // j for radius
        {  
            printf("%d %d\n",i, j );
            printf("%d == %d\n",start[j],i );
            if(start[j] == i )  
            {  
                printf("shit\n");
                pegs[i] = j;  
                break;  
            }  
        }
    }  
    
    // printf("end\n");
}  

void fun(int depth)//steps: 0-7  
{  
    if(depth++ >= minSteps)  
        return;  

    for(int i = 1; i <= K; ++i)  
    {  
        for(int j = 1; j <= K; ++j)  
        {  
            if(pegs[i] < pegs[j])// possible step, go ahead!  
            {  
                int disc = pegs[i];  
                start[pegs[i]] = j;  
                initPeg();  
                steps[depth][0] = i;  
                steps[depth][1] = j;  

                //after the switch  
                bool flag = true;  
                for(int idx = 1; idx <= N; ++idx)  
                    if(start[idx] != last[idx])  
                    {  
                        flag = false;  
                        break;  
                    }  
                if(flag == true)//find one  
                {  
                    minSteps = depth;  
                    for(int idx = 1; idx <= depth; ++idx)  
                    {  
                        optimSteps[idx][0] = steps[idx][0];  
                        optimSteps[idx][1] = steps[idx][1];  
                    }  
                    return ;  
                }  
                else//not a result  
                {  
                    fun(depth);  
                }  
                start[disc] = i;  
                initPeg();  
            }  
        }  
    }  
}  

int main()  
{  
    cin >> N;  
    cin >> K;  
    for(int i = 1; i <= N; ++i)  
        cin >> start[i];  
    for(int i = 1; i <= N; ++i)  
        cin >> last[i];  
    initPeg();  
    printf("zzz\n");
for (int i = 1; i <= K; i++) {
                printf("pegs[%d] = %d\n", i, pegs[i]);

    }
    // fun(0);  
    // print();  
    return 0;  
}  