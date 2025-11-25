#include "TSP.hpp"

#include <iostream>
#include <cstdio>

int main() {
    cost_matrix_t cm = {{INF, 10, 8,   19, 12},
                      {10, INF, 20,  6,  3},
                      {8,   20, INF, 4,  2},
                      {19,  6,  4, INF,  7},
                        {12,  3,  2,   7, INF}};

    /* Rozwiązania:
     * 32 : 2 3 4 1 0
     * 32 : 1 4 3 2 0
     */

    //cost_matrix_t cm {
    //        {INF, 12,   3,  45,   6},
    //        {78, INF,  90,  21,   3},
    //        { 5,  56, INF,  23,  98},
    //        {12,   6,   8, INF,  34},
    //        { 3,  98,   3,   2, INF}
   //};

    /* Rozwiązanie:
     * 30 : 4 3 2 0 1
    */

//    cost_matrix_t cm {
//            {INF,  3,  4,  2,  7},
//            {3,  INF,  4,  6,  3},
//            {4,  4,  INF,  5,  8},
//            {2,  6,  5,  INF,  6},
//            {7,  3,  8,  6,  INF},
//    };

    /* Rozwiązania:
     * 19 : 4 3 0 2 1
     * 19 : 1 2 0 3 4
    */

    printf("dupa\n"); //test czy działa cokolwiek

    // get_min_values_in_rows() test
    auto mins_r = CostMatrix(cm).get_min_values_in_rows();
    for (auto x : mins_r)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    // get_min_values_in_cols() test
    auto mins_c = CostMatrix(cm).get_min_values_in_cols();
    for (auto x : mins_c)
    {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    // reduce_rows() test
    CostMatrix cm_obj(cm);
    for (int row = 0; row < cm_obj.size(); ++row)
    {
        for (int col = 0; col < cm_obj.size(); ++col)
        {
            std::cout << cm_obj[row][col] << ' ';
        }
        std::cout << '\n';
    }
    std::cout<<'\n'<<std::endl;
    std::cout<<cm_obj.reduce_rows();
    std::cout<<'\n'<<std::endl;
    for (int row = 0; row < cm_obj.size(); ++row)
    {
        for (int col = 0; col < cm_obj.size(); ++col)
        {
            std::cout << cm_obj[row][col] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    //reduce_cols() test

    CostMatrix cm_obj2(cm);
    for (int row = 0; row < cm_obj2.size(); ++row)
    {
        for (int col = 0; col < cm_obj2.size(); ++col)
        {
            std::cout << cm_obj2[row][col] << ' ';
        }
        std::cout << '\n';
    }
    std::cout<<'\n'<<std::endl;
    std::cout<<cm_obj2.reduce_cols();
    std::cout<<'\n'<<std::endl;
    for (int row = 0; row < cm_obj2.size(); ++row)
    {
        for (int col = 0; col < cm_obj2.size(); ++col)
        {
            std::cout << cm_obj2[row][col] << ' ';
        }
        std::cout << '\n';
    }
    std::cout<<'\n'<<std::endl;
//test get_vertex_cost()
    std::cout<<"get_vertex_id TEST\n"<<std::endl;
    CostMatrix cm_obj3(cm);
    for (int row = 0; row < cm_obj3.size(); ++row)
    {
        for (int col = 0; col < cm_obj3.size(); ++col)
        {
            std::cout << cm_obj3[row][col] << ' ';
        }
        std::cout << '\n';
    }
    std::cout<<'\n'<<std::endl;
    cm_obj3.reduce_rows();
    cm_obj3.reduce_cols();
    for (int row = 0; row < cm_obj3.size(); ++row)
    {
        for (int col = 0; col < cm_obj3.size(); ++col)
        {
            std::cout << cm_obj3[row][col] << ' ';
        }
        std::cout << '\n';
    }
    std::cout<<'\n'<<std::endl;
    std::cout<<cm_obj3.get_vertex_cost(4,2)<<std::endl;

    CostMatrix cm_obj4(cm);
    StageState ss(cm_obj4);
    std::cout<<ss.reduce_cost_matrix()<<std::endl;
    std::cout<<"\n new_vertex test"<<'\n'<<std::endl;
    CostMatrix cm_obj5(cm);
    StageState ss1(cm_obj5);
    NewVertex new_vert = ss1.choose_new_vertex();
    std::cout<<"wierzcholek: "<<new_vert.coordinates.row<<' '<<new_vert.coordinates.col<<"\n koszt: "<<new_vert.cost<<std::endl;

    tsp_solutions_t solutions = solve_tsp(cm);

    for (auto elem : solutions) {
        std::cout << elem.lower_bound << " : ";
        for (auto pelem : elem.path) {
            std::cout << pelem << " ";
        }
        std::cout << "\n";
    }
    //test reduce_cost_matrix()




    return EXIT_SUCCESS;
}
