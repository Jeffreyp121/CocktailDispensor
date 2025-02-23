#ifndef _INTERFACES_OBERSERVER_H_
#define _INTERFACES_OBERSERVER_H_
 
class IObserver
{
    public:
        virtual void Update(void* parameters) = 0;
        virtual ~IObserver() {};
};


#endif /* _INTERFACES_OBERSERVER_H_ */