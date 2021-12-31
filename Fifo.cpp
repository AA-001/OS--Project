#include<iostream>
using namespace std;
int main()
{
    int i,j,n,a[50],frame[10],no,k,avail,count=0, count1=0;
    cout<<"\n ENTER THE NUMBER OF PAGES:\n";
    cin>>n;
    cout<<"\n ENTER THE PAGE NUMBER :\n";
    for(i=1;i<=n;i++)
        cin>>a[i];
    cout<<"\n ENTER THE NUMBER OF FRAMES :";
    cin>>no;
    for(i=0;i<no;i++)
        frame[i]= -1;    //set all frames to -1 at beginning
    j=0;                 // represents frame number (0,1,2) for 3 frames
    cout<<"\nref string\t \tpage frames\n";
    for(i=1;i<=n;i++)
    {
        cout<<"\t"<<a[i]<<"\t";   // a[i] prints ref string
        avail=0;                 // to check faults
        for(k=0;k<no;k++)
            if(frame[k]==a[i]){
                avail=1;            //to check hits
                count1++;
                cout<<"  ->";
                 for(k=0;k<no;k++)
                	cout<<"\t"<<frame[k];
            }
            if (avail==0){
                frame[j]=a[i];       // sets ref string value to frame no. specified by J
                j=(j+1)%no;          //to indicate next frame to be replaced
                count++;
                for(k=0;k<no;k++)
                    cout<<"\t"<<frame[k];
            }
        cout<<"\n";
    }
    cout<<"\n\nPage Fault Is: "<<count;
    cout<<"\nMiss Ratio:  "<<count<<"/"<<n<<" %";
    cout<<"\n\nNumber of Hits Is: "<<count1;
    cout<<"\nHit Ratio: "<<count1<<"/"<<n<<" %";
    return 0;
}