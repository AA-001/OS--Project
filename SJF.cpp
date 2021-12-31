#include <iostream>
using namespace std;
int mat[10][7];     // total 6 columns req 
 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
void arrangeArrival(int num, int mat[][7])
{                                                  // sorted acc to Arrival time-(bubble sort) 
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (mat[j][1] > mat[j + 1][1]) {
                for (int k = 0; k < 6; k++) {
                    swap(mat[j][k], mat[j + 1][k]);  //swaps process no., AT & BT,
                }
            }
        }
    }
}
 
void completionTime(int num, int mat[][7])
{
    int temp, val;           // below 3 r for only 1st process after arranging
    mat[0][3] = mat[0][1] + mat[0][2];   // CT for first process
    mat[0][5] = mat[0][3] - mat[0][1];   //TAT=CT-AT
    mat[0][4] = mat[0][5] - mat[0][2];
    mat[0][6] = mat[0][1] -mat[0][1]; //WT= TAT -BT
 
    for (int i = 1; i < num; i++) {   // loop start from 2nd process
        temp = mat[i - 1][3];    //store CT of prev process
        int low = mat[i][2];     //store BT of cur process
        for (int j = i; j < num; j++) {
            if (temp >= mat[j][1] && low >= mat[j][2]) { //if CT of previous >= AT of cur process & Cur BT >= arrived BT
                low = mat[j][2];    // thn set arrived BT as low(shortest job)
                val = j;            // store that process no. with low BT in variable
            }
			// basically checks BT of all the arrived processes n sets lowest BT
        }
        mat[val][3] = temp + mat[val][2];     // cal CT-3,WT-4,TAT-5 for j process
        mat[val][5] = mat[val][3] - mat[val][1];
        mat[val][4] = mat[val][5] - mat[val][2];
        mat[val][6] = temp - mat[val][1];
                for (int k = 0; k < 7; k++) {
            swap(mat[val][k], mat[i][k]);    // to get in order in wch cpu allocates the process
        }
    }
}
 
int main()
{
    int num, temp; 
	float avgtat=0, avgwt=0,avgRT=0;
    cout << "Enter number of Process: ";
    cin >> num;
    cout << "...Enter the process ID...\n";
    for (int i = 0; i < num; i++) {
        cout << "...Process " << i + 1 << "...\n";
        cout << "Enter Process Id: ";     // 1st col- process id
        cin >> mat[i][0];
        cout << "Enter Arrival Time: ";   //2nd col- arrival time
        cin >> mat[i][1];
        cout << "Enter Burst Time: ";     //3rd col- burst time
        cin >> mat[i][2];
    }
    cout << "Before Arrange...\n";
    cout << "Process ID\tArrival Time\tBurst Time\n";
    for (int i = 0; i < num; i++) {
        cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
             << mat[i][2] << "\n";
    }
    arrangeArrival(num, mat);
    completionTime(num, mat);
    cout << "Final Result...\n";
    cout << "Process ID\tArrival Time\tBurst Time\tCompletion Time \tWaiting "
            "Time\tTurnaround Time\tResponse Time\n";
    for (int i = 0; i < num; i++) {
        cout << mat[i][0] << "\t\t" << mat[i][1] << "\t\t"
             << mat[i][2] << "\t\t" << mat[i][3] << "\t\t\t"
             << mat[i][4] << "\t\t"<< mat[i][5] << "\t\t"<< mat[i][6]<< "\n";
    }
    for(int i=0;i<num;i++)
    {
    	avgtat+=mat[i][5];
    	avgwt+=mat[i][4];
        avgRT+=mat[i][6];
	}
	avgtat= avgtat/num;
	avgwt= avgwt/num;
    avgRT= avgRT/num;
	cout<<"\n\nGrant Chart (process order): ";
	for (int i = 0; i < num; i++)
	cout<<mat[i][0]<<" ";
	cout<<"\nAverage turn around Time = "<<avgtat<<" ms";
	cout<<"\nAverage waiting Time = "<<avgwt<<" ms";
    cout<<"\nAverage Response Time = "<<avgRT<<" ms";
}