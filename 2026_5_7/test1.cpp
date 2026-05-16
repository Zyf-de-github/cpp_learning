#include <bits/stdc++.h>
using namespace std;



HW Timer API:

typedef struct Node
{
    uint32_t abs_time=0;
    pfunc task=NULL;
    Node next=NULL;
}Node;
Node head;

uint64_t get_now();
void set_timer(uint32_t timeout);
void timer_fired(void); 
 
void (*pfunc)(void);
int timer_start(uint32_t timeout, pfunc callback)
{
    temp.abs_time=timeout+get_now();
    temp.task=callback;
    Node x=head;
    while(x.next==NULL||x.next.abs_time>=temp.abs_time)x=x.next;
    if(x.next==NULL)x.next=temp;
    else
    {
        temp.next=x.next.next;
        x.next=temp;
    }
    set_timer(head.next.abs_time-get_now());
}
 
void timer_fired(void) 
{
    Node temp=head;
    head=head.next;
    delate(temp);
    if(head.next!=NULL)set_timer(head.next.abs_time-get_now());
}
 
APP1:
timer_start(5, callback1);
timer_start(10, callback2);
 
APP2:
timer_start(5, callback3);


int main()
{
    
    return 0;
}
