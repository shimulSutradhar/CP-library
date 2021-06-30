#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("no-stack-protector")
 
#if defined(ONLINE_JUDGE)
    #pragma GCC target("aes,avx,avx2,avx512f,avx512dq,avx512cd,avx512bw,avx512vl,f16c,fma,mmx,pclmul,popcnt,rdrnd,sse,sse2,sse3,sse4.1,sse4.2,ssse3")
#endif
// use it in the top
