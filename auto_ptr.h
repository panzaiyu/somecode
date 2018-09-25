#ifndef AUTO_PTR_H
#define AUTO_PTR_H

template <class T>
class auto_ptr
{
    public:
        explicit auto_ptr(T* ptr = nullptr) throw(): ap(ptr)
        {
        }
        virtual ~auto_ptr() throw()
        {
            delete ap;
        }

        auto_ptr(auto_ptr& other) throw():ap(other.release())
        {
        }
        template <class Y>
        auto_ptr(auto_ptr<Y> other) throw():ap(other.release())
        {
        }

        auto_ptr& operator=(auto_ptr& other) throw()
        {
            reset(other.release());
            return *this;
        }
        template <class Y>
        auto_ptr& operator=(auto_ptr<Y>& other) throw()
        {
            reset(other.release());
            return *this;
        }

        T* operator*()
        {
            return *ap;
        }
        T* operator->()
        {
            return ap;
        }

        T* get() const throw()
        {
            return ap;
        }
        T* release() throw()
        {
            T* tmp(ap);
            ap = nullptr;
            return tmp;
        }

        void reset(T* ptr = nullptr) throw()
        {
            if(ap != ptr)
            {
                delete ap;
                ap = ptr;
            }
        }

    private:
        T* ap;
};

#endif // AUTO_PTR_H
