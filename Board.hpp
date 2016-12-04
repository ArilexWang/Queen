//
//  Board.hpp
//  Queen
//
//  Created by Ricardo on 2016/12/1.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Board{
private:
    friend ostream& operator << (ostream&,Board&);
    char** _space;
    int* _state;
    int _size;
    int _sum;
public:
    Board(int size);
    void print();
    int getSize() const;
    int getSum() const;
    void setData(int row,int column,char value);
    bool isSafe(int row, int column);
    void backTrace(int k);
    void recover();
};

#endif /* Board_hpp */
