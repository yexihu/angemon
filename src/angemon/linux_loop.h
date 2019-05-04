#ifndef LINUX_LOOP_H
#define LINUX_LOOP_H
#include"loop.h"
#include <sys/epoll.h>
using namespace angemon::base;
namespace angemon {
namespace linux {

class Loop:public base::Loop
{
private:
    map<int, Event *> _active;
    int _efd;
    const int MAXEVENTS = 64;
    epoll_event  _ev ;

public:
    Loop();

    ~Loop() = default;

    virtual void register_(Event *&evt) final;

    virtual void unregister_(Event *&evt) final;

    virtual void modify(Event *&evt, int ev) final;

    virtual vector<Event *> poll() final;
};
}}
#endif // LINUX_LOOP_H
