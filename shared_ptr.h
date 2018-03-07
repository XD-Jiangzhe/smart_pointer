#ifndef SMART_POINT
#define SMART_POINT

#include <assert.h>

#include <iostream>

namespace smart_point{

    template<typename T>
    class shared_ptr;

    template <typename T>
    class u_ptr{

        friend class shared_ptr<T>;

        u_ptr(T* p):val(p), count(1){}
        ~u_ptr(){delete val;}

        T* val;
        int count;
    };
    
    template<typename T>
    class shared_ptr{

        public:
        shared_ptr(T* t):ptr(new u_ptr<T>(t)){}
        shared_ptr(const shared_ptr<T>& rhs):ptr(rhs.ptr){
            std::cout<<"copy constructor"<<std::endl;
            rhs.ptr->count++;
        }
        ~shared_ptr()
        {
            assert(ptr->count>0);
            if(--ptr->count == 0)
                delete ptr;
        }

        shared_ptr& operator=(shared_ptr<T>& rhs)
        {
            ++rhs.ptr->count;
            if(--ptr->count==0)
            {
                delete  ptr;
                std::cout<<"delete ptr"<<std::endl;                
            }
            ptr= rhs.ptr;

            return *this;
        }
        T& operator*()
        {
            return *(ptr->val);
        }

        T* operator->()
        {
            return ptr->val;
        }

        size_t ues_count()const{
            return ptr->count;
        }
        private:
            u_ptr<T> *ptr ;
    };
}


#endif