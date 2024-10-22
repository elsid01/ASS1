#include "myStack.h"
#include "myStack.cpp"
#include "LL.h"
#include "LL.cpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
    LL< myStack<string> > accordion;

    ifstream input;
    input.open("cards01.txt");
    if (input.fail()) {
        cout << "File does not exist " << endl;
        return 0;
    }

    string card;
    while (input >> card) {
        myStack<string> newStack;
        newStack.push(card);
        accordion.tailInsert(newStack);
    }
    input.close();

    bool moved;
    do {
        moved = false;
        LL< myStack<string> >::iterator it = accordion.begin();
        while (it != accordion.end()) {
            LL< myStack<string> >::iterator it1 = it, it2 = it;

            if (it1 != accordion.begin()) {
                --it1;
            } else {
                ++it;
                continue;
            }

            if (it != accordion.begin()) {
                --it2;
                if (it2 != accordion.begin()) {
                    --it2;
                    if (it2 != accordion.begin()) {
                        --it2;
                    } else {
                        it2 = accordion.end();
                    }
                } else {
                    it2 = accordion.end();
                }
            } else {
                it2 = accordion.end();
            }

            if (it1 != accordion.end() && ((*it).peek()[0] == (*it1).peek()[0] || (*it).peek()[1] == (*it1).peek()[1])) {
                (*it1).push((*it).pop());
                if ((*it).isEmpty()) {
                    accordion.removeAtPosition(it);
                }
                moved = true;
                break;
            }

            if (it2 != accordion.end() && ((*it).peek()[0] == (*it2).peek()[0] || (*it).peek()[1] == (*it2).peek()[1])) {
                (*it2).push((*it).pop());
                if ((*it).isEmpty()) {
                    accordion.removeAtPosition(it);
                }
                moved = true;
                break;
            }

            ++it;
        }
    } while (moved);

    LL< myStack<string> >::iterator it;
    int count = 0;
    for (it = accordion.begin(); it != accordion.end(); ++it) {
        cout << (*it).peek() << " ";
        count++;
    }
    cout << endl;
    cout << "The rest is " << count << endl;

    return 0;
}




//#include "myStack.h"
//#include "myStack.cpp"
//#include "LL.h"
//#include "LL.cpp"
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <string>
//
//using namespace std;
//
//int main() {
//    LL< myStack<string> > accordion;
//
//    ifstream input;
//    input.open("cards01.txt");
//    if (input.fail()) {
//        cout << "File does not exist " << endl;
//        return 0;
//    }
//
//    string card;
//    while (input >> card) {
//        myStack<string> newStack;
//        newStack.push(card);
//        accordion.tailInsert(newStack);
//    }
//    input.close();
//
//    LL< myStack<string> >::iterator p3, p2, p1;
//
//    p3 = accordion.end();
//    --p3;
//
//    int countIt = 0;
//    p2 = accordion.end();
//    while (countIt < 4) {
//        --p2;
//        countIt++;
//    }
//
//    p1 = p2;
//    while (countIt < 5) {
//        --p1;
//        countIt++;
//    }
//
//    while (p1 != accordion.begin()) {
//        --p3;
//        --p2;
//        --p1;
//
//        if ((*p3).peek()[0] == (*p2).peek()[0] || (*p3).peek()[1] == (*p2).peek()[1]) {
//            (*p2).push((*p3).pop());
//
//            if ((*p3).isEmpty()) {
//                accordion.removeAtPosition(p3);
//                p3 = p2;
//                --p2;
//                --p1;
//            }
//        }
//
//        if ((*p2).peek()[0] == (*p1).peek()[0] || (*p2).peek()[1] == (*p1).peek()[1]) {
//            (*p1).push((*p2).pop());
//
//            if ((*p2).isEmpty()) {
//                accordion.removeAtPosition(p2);
//                p2 = p1;
//                --p1;
//                p3 = p2;
//            }
//        }
//    }
//
//    LL< myStack<string> >::iterator it;
//    
//    for (it = accordion.begin(); it != accordion.end(); ++it) {
//        cout << (*it).peek() << " ";
//       
//    }
//
//    return 0;
//}




//#include "myStack.h"
//#include "myStack.cpp"
//#include "LL.h"
//#include "LL.cpp"
//#include <iostream>
//#include <fstream>
//#include <cstdlib>
//#include <string>
//using namespace std;
//
//
//
//
//int main()
//{
//    
//        LL< myStack<string> > accordion;
//    
//        ifstream input;
//        input.open("cards01.txt");
//        if(input.fail())
//        {
//            cout<<"File does not exist " << endl;
//            return 0;
//        }
//        
//        string card;
//        
//        input >> card;
//        
//        //int count = 0;
//        while(!input.eof())
//        {
//            input>> card;
//            myStack<string> newStack;
//            newStack.push(card);
//            accordion.tailInsert(newStack);
//            
//        }
//        
//    
//
//
//       LL< myStack<string> > :: iterator p3 , p2 , p1;
//       
//          p3 = accordion.end();
//          --p3;
//          
//    int countIt = 0;
//    p2 = accordion.end();
//    while(countIt < 4)
//    {
//        --p2;
//        countIt++;
//    }
//    
//    p1 = p2;
//    
//    while(countIt < 5)
//    {
//        --p1;
//        countIt++;
//    }
//    
//    
//
//    
//    while(p1 != accordion.begin())
//    {
//        
//        p3 = --p3;
//        p2 = --p2;
//        p1 = --p1;
//       
//        if((*p3).peek()[0] == (*p2).peek()[0] || (*p3).peek()[1] == (*p2).peek()[1])
//        {
//            (*p2).push((*p3).pop());
//            
//            if((*p3).isEmpty())
//            {
//                
//                accordion.removeAtPosition(p3);
//                p3 = p2;
//                --p2;
//                --p1;
//                // assign the empty stack to  a temperary stack
//                // move the iterators one position backward
//                //delete the temperary stack
//            }
//        }
//        
//        if((*p2).peek()[0] == (*p1).peek()[0] || (*p2).peek()[1] == (*p2).peek()[1])
//        {
//            (*p1).push((*p2).pop());
//            
//            if((*p2).isEmpty())
//            {
//                accordion.removeAtPosition(p2);
//                p2 = p1;
//                p3 = p2;
//                // assign the empty stack to  a temperary stack
//                // move the iterators one position backward
//                //delete the temperary stack
//            }
//        }
//        
//    }
//
//   
//       LL< myStack<string> > :: iterator it;
//       int counT = 0;
//       for (it = accordion.begin(); it != accordion.end(); it++)
//       {
//          cout <<(*it).peek() << " ";
//           counT++;
//       }
//    cout << endl;
//       cout << "The rest is " << counT << endl;
//       
//    
//       return 0;
//}
//
//
