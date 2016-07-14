//
//  main.cpp
//  test
//
//  Created by vivi on 7/8/16.
//  Copyright © 2016 vivi. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

ofstream fout("/private/etc/hosts", ios_base::app);

int main(int argc, const char * argv[]) {
    fout << endl << "127.0.0.1\t" << "www.youku.com" << endl;
    fout << "127.0.0.1\t" << "www.tudou.com" << endl;
    fout.close();
}
