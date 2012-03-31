#ifndef __SINGLETON_HPP__
#define __SINGLETON_HPP__

template<class T> class Singleton {
public:
    static T& instance() {
        static T i;
        return i;
    }

private:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

protected:
    Singleton() {}
};

#endif

