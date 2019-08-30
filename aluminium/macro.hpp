#ifndef ALUMINIUM_MACRO
#define ALUMINIUM_MACRO


#define ALUMINIUM_MACRO_FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define ALUMINIUM_MACRO_REP(i, n) ALUMINIUM_MACRO_FOR(i, 0, n)
#define ALUMINIUM_MACRO_LOOP(n) ALUMINIUM_MACRO_REP(_LOOP_COUNTER, n)

#define al_FOR(i, a, b) ALUMINIUM_MACRO_FOR(i, a, b)
#define al_REP(i, n) ALUMINIUM_MACRO_REP(i, n)
#define al_LOOP(n) ALUMINIUM_MACRO_LOOP(n)


#endif
