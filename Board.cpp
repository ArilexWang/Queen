//
//  Board.cpp
//  Queen
//
//  Created by Ricardo on 2016/12/1.
//  Copyright © 2016年 Ricardo. All rights reserved.
//

#include "Board.hpp"
#include <cmath>

Board::Board(int size){
    _size = size;
    _space = new char*[size+1];
    for (int i = 1; i <= size; i++) {
        _space[i] = new char[size+1];
    }
    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= size; ++j) {
            _space[i][j] = '0';
        }
    }
    _state = new int[size+1];
    _sum = 0;
}

void Board::print(){
    for (int i = 1;i <= _size ; ++i) {
        for (int j = 1; j <= _size; ++j) {
            cout << _space[i][j] << " ";
        }
        cout << endl;
    }
}

ostream& operator << (ostream& o,Board& refB){
    refB.print();
    return o;
}

int Board::getSize() const{
    return _size;
}

int Board::getSum()const{
    return _sum;
}

void Board::setData(int x,int y,char value){
    _space[x][y] = value;
}

bool Board::isSafe(int row,int column){
    for (int i = 1; i < row; i++) {
        if ((_state[i]-column) == (i-row)||(_state[i] - column == row - i)||(_state[i] == column)) {
            return false;
        }
    }
    return true;
}

void Board::recover(){
    for (int i = 1; i <= _size; ++i) {
        for (int j = 1; j <= _size; ++j) {
            _space[i][j] = '0';
        }
    }
}

void Board::backTrace(int k){
    if (k > _size) {
        cout << "解法" << ++_sum << "：";
        for (int i = 1; i <= _size; ++i) {
            _space[i][_state[i]] = 'X';
        }
        cout << endl;
        print();
        recover();
    } else{
        for (int i = 1; i <= _size; ++i) {
            if (isSafe(k, i)) {
                _state[k] = i;
                backTrace(k+1);
            }
        }
    }
}
