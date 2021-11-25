#include<iostream>
#include<list>
#include<fstream>
using namespace std;

template<class T>
class NodoB
{
    public:
       int                  m_Grado;
       T                    m_Dato;
       NodoB<T>  *          m_Padre;
       list< NodoB<T> * >   m_Sons;

       NodoB(T d)
       {
           m_Dato = d;
           m_Grado = 0;
           m_Padre = 0;
       } 
};

template<class T>
class Binomial_Heap
{
     private:
       list< NodoB<T> * >  m_Roots;
       NodoB<T>         *  m_pMin;
     private:
       void Compactar(); 
       void Unir(NodoB<T> * p ,NodoB<T> * q );  
     public:
      Binomial_Heap(){ m_pMin = 0; };
      ~Binomial_Heap(){};
      void Insert(T d); 
      void Extrac_Min(); 
      void Delete(NodoB<T> * e); 
      void Decrease_Key(NodoB<T> * e, T val); 
      NodoB<T> * GetMin();
      /**************/
};


template<class T>
void Binomial_Heap<T>::Insert(T d) 
{
    NodoB<T> * pNew = new NodoB<T>(d);
    m_Roots.push_front(pNew);
    //Compactar();
}

template<class T>
void Binomial_Heap<T>::Delete(NodoB<T> * e)
{
    Decrease_Key(e,m_pMin->m_Dato - 1);
    m_pMin = e;
    //Extrac_Min();
}


template<class T>
void Binomial_Heap<T>::Extrac_Min()
{
    typename list<NodoB<T>*>::iterator it = m_pMin->m_Sons.begin();
    for(; it != m_pMin->m_Sons.end(); it++)
           m_Roots.push_front(*it);
    m_Roots.remove(m_pMin);
    //Compactar();  
}


template<class T>
void Binomial_Heap<T>::Decrease_Key(NodoB<T> * e, T val) 
{
    e->m_Dato = val;
    while(e->m_Padre && e->m_Padre->m_Dato  >  e->m_Dato)
    {
        swap( e->m_Dato,e->m_Padre->m_Dato);
        e = e->m_Padre;
    }

}

template<class T>
NodoB<T> * Binomial_Heap<T>::GetMin()
{
    return m_pMin;
}

// Log(n)
template<class T>
void Binomial_Heap<T>::Compactar() 
{


}



// O(1)
template<class T>
void Binomial_Heap<T>::Unir(NodoB<T> * p ,NodoB<T> * q ) // O(1)
{
    if(p->m_Dato < q->m_Dato) {
        p->m_Sons.push_front(q); 
        p->m_Grado++; 
        q->m_Padre = p; 
        m_Roots.remove(q); 
    }
    else { 
        q->m_Sons.push_front(p); 
        q->m_Grado++; 
        p->m_Padre = q; 
        m_Roots.remove(p);
    }
}



int main()
{
    Binomial_Heap<int> A;
    for(int i=0; i<10; i++)
    {
        //A.Insert(i);
    }
   
    return 1;
}
