#include <cstdlib>
#include <list>
#include <forward_list>
#include <vector>

#include <benchmark/benchmark.h>

extern "C" {
#include <loudon/slist.h>
}


// ### ListInit ### //

static void BM_ListInit_slist(benchmark::State& state) {
    for (auto _ : state) {
        List list;
        list_init(&list, NULL);
    }
}    

BENCHMARK(BM_ListInit_slist);

static void BM_ListInit_cpp_forward_list(benchmark::State& state) {
    for (auto _ : state)
        std::forward_list<int> list;
}   

BENCHMARK(BM_ListInit_cpp_forward_list);

static void BM_ListInit_cpp_list(benchmark::State& state) {
    for (auto _ : state)
        std::list<int> list;
}   

BENCHMARK(BM_ListInit_cpp_list);

// ### ListInit ### //

static void BM_ListPushFront_slist(benchmark::State& state) {
    List list;
    list_init(&list, NULL);
    int rint = rand();
    for (auto _ : state)
        list_ins_next(&list, NULL, &rint);
}    

BENCHMARK(BM_ListPushFront_slist);

static void BM_ListPushFront_cpp_forward_list(benchmark::State& state) {
    std::forward_list<int> list;
    int rint = rand();
    for (auto _ : state)
        list.push_front(rint);
}    

BENCHMARK(BM_ListPushFront_cpp_forward_list);

static void BM_ListPushFront_cpp_list(benchmark::State& state) {
    std::list<int> list;
    int rint = rand();
    for (auto _ : state)
        list.push_front(rint);
}    

BENCHMARK(BM_ListPushFront_cpp_list);

BENCHMARK_MAIN()//;
