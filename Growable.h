#include<iostream>
using namespace std;

template<typename T>
class Growable
{
private:
     T * ptr;
     int size;
protected:
    T * Allocate(int);
	void Copy(T *&,T*);
public:
    Growable();
    Growable(int);
    ~Growable();
    T at(int)const;
	T operator[](int)const;
	T front()const;
	T back()const;
    int Size()const;
	bool empty()const;
    void push_back(T);
    void pop();
    void print();
};
template<typename T>
Growable<T> ::Growable()
{
    cout <<"Constructor..!!"<<endl;
    ptr = nullptr;
    size = 0;
}
template<typename T>
Growable<T> ::Growable(int size)
{
    this->size = size;
    ptr =  new T[this->size]; 
}
template<typename T>
Growable<T>::~Growable()
{
    cout<<"Destructor...!!!"<<endl;
    if(size !=0 && ptr)
    {
        delete [] ptr;
        ptr = nullptr;
    }
}
template<typename T>
T* Growable<T>::Allocate(int n)
{
	return new T[n];
}
template<typename T>
void Growable<T>::Copy(T *&v , T*n)
{
	int i = 0;
	while(v[i]=n[i])i++;
}
template<typename T>
void Growable<T>::push_back(T val)
{
    if(size == 0)
    {
        this->ptr =Allocate(this->size+1);
        ptr[size] = val;
        size++;
        return;
    }
    T * newptr =Allocate(this->size+1);
   Copy(newptr,this-> ptr);
    if(size!= 0)
    {
        delete []this->ptr;
        ptr =  nullptr;
    }
    newptr[size]  = val;
    this->ptr = newptr;
    size++;
}
template<typename T>
void Growable<T>::pop()
{
     if(size == 0)
	{
		throw invalid_argument("vector is empty cannot do pop back \n");
		return;
	}
	T * newptr = Allocate(this->size-1);
     Copy(newptr,this->ptr);
    if(size!= 0)
    {
        delete[] this->ptr;
        ptr =  nullptr;
    }
    this->ptr = newptr;
    size--;
}
template<typename T>
void Growable<T>::print()
{
    for(int i=0; i<size; i++)
    {
        cout << this->ptr[i]<< " ";
    }
    cout <<endl;
}
template<typename T>
T Growable<T>::back()const
{
	if (this->size == 0){ throw invalid_argument("vector is not initalize"); };
	return this->ptr[this->size - 1];
}
template<typename T>
int Growable<T>::Size()const
{
	return this->size;
}
template<typename T>
bool Growable<T>::empty()const
{
	if(this->size == 0)
    {
        return true;
    }
    return false;
}
template<typename T>
 T Growable<T>::operator[](int n)const
{
	if (n >= this->size){ throw invalid_argument("out of range... ending the program"); exit(1); }
	return this->ptr[n];
}
template<typename T>
T Growable<T>::front()const
{
	if (this->size == 0){ throw invalid_argument("vector is not initalize"); };
	return this->ptr[0];
}
template<typename T>
T Growable<T>::at(int index)const
{
	if (index >= this->size){ throw invalid_argument("out of range... ending the program"); exit(1); }
	return this->ptr[index];
}