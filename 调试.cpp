#include <iostream>
using namespace std;
class IMotor{
    public:
    virtual void setoutput(int a)=0;
    virtual int getspeed()=0;
    virtual void update()=0;
    virtual ~IMotor(){}
};
class djimotor:public IMotor{
    public:
    void setoutput(int a){
        cout<<"[CAN] ID:0x201, 电流:"<<a<<endl;
    }
    int getspeed(){
        return 1000;
    }
    void update(){
    
    }
};
class simmotor:public IMotor{
    private:
    int velocity;
    int f;
    const int r=5;
    public:
    simmotor():velocity(0),f(0){}
    void setoutput(int a){
        f=a;
    }
    int getspeed(){
        return velocity;
    }
    void update(){
        velocity+=(f-r);
        if(velocity<0) velocity=0;
    }
};
void testmotor(IMotor* m){
    m->setoutput(50);
    m->update();
    cout<<"转速："<<m->getspeed()<<" rpm"<<endl;
}

