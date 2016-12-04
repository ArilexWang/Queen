//
//  main.cpp
//  Queen
//
//  Created by Ricardo on 2016/11/28.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include <iostream>
#include "Board.hpp"
int main(int argc, const char * argv[]) {
    int size;
    cout << "请输入皇后个数：";
    cin >> size;
    Board chess(size);
    chess.backTrace(1);
    cout << "共有" <<chess.getSum() << "种解法" << endl;
    return 0;
}
