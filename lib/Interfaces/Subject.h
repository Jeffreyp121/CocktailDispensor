#ifndef _INTERFACES_SUBJECT_H_
#define _INTERFACES_SUBJECT_H_

#include <Observer.h>

class ISubject
{
    public:
        virtual void AddObserver(IObserver* oberserver) = 0;
        virtual void NotifyObservers(void* paramaters) = 0;
        virtual ~ISubject() {};
};


#endif /* _INTERFACES_SUBJECT_H_ */