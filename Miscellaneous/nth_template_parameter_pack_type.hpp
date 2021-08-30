#if __cplusplus >= 201103L
/* A simple Work-around for deducing Nth-type in Template Parameter-Pack (at compile-time) */

template<int N,typename... T>
struct get_nth_type;//i.e. forward declaration of primary template struct

template<typename T0,typename... T>
struct get_nth_type<0,T0,T...>{//i.e. partially specialized struct template
    typedef T0 type;
};
template<int N,typename T0,typename... T>
struct get_nth_type<N,T0,T...>{//i.e. partially specialized struct template
    typedef typename get_nth_type<N-1,T...>::type type;
};

template<int N,typename... T>
using get_type=typename get_nth_type<N,T...>::type;//i.e. simplifying previous formatted name
//Using Format: get_type<1,string,int,bool,char> -> returns int type

#endif
