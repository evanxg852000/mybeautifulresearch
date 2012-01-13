#ifndef VECTOR_H
#define VECTOR_H

#include "viterator.h"


template<typename T>
class Vector{
public:

    class Viterator{
    public:
        Viterator(Vector<T>* container,int location){
            this->_container=container;
            this->_position=location;
        }

        Viterator& next(){
            this->_position++;
            return *(this);
        }

        T& value(){
            return this->_container->at(this->_position);
        }

        void reset(){
            this->_position=0;
        }

        bool operator!=(const Viterator& it){
            return (this->_position<it._position);
        }

        bool isValid(){
             return (this->_position<this->_container->end()._position);
        }

    private:
        Vector<T>* _container;
        int _position;
    };

    Vector(){
        this->_capacity=0;
        this->_size=0;
        this->_content=0;
    }

    virtual ~Vector(){
        if(this->_content!=0){
            delete[] this->_content;
        }

    }

    void insert(T item){
        if(this->_size==this->_capacity){
            this->allocate(10);//allocate in +10
        }
        this->_content[this->_size]=item;
        this->_size++;
    }

    T& at(int index){
        if(index>=this->_size){
            throw "Out of bound Exception";
        }
        return this->_content[index];
    }

    int size(){
        return this->_size;
    }

    const Viterator& begin(){
        return Viterator(this,0);
    }

    Viterator end(){
        return Viterator(this,this->_size);;
    }

    Viterator  it(int index){
        if(index>=this->_size){
            return this->end();
        }
        return Viterator(this,index);
    }

private:
    void allocate(int grow){
            T* temp=new T[this->_capacity+grow];
            for(int i=0;i<this->_size;i++){
                temp[i]=this->_content[i];
            }
            delete[] this->_content;
            this->_content=temp;
            this->_capacity=this->_capacity+grow;
    }

    T* _content; //array[]
    int _capacity; //space available
    int _size; //nb element

};



#endif
