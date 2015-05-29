#ifndef _HEAP_H_
#define _HEAP_H_

#include "absheap.h"

class Heap: public AbsHeap {

public:
	virtual void push(int _key, char _element)
	{
		Node input;
		input.key = _key;
		input.element = _element;
		if( isEmpty() )
		{
			ary[ 0 ] = input;
		}
		else
		{
			int i = size;
			ary[ i ] = input;
			while(ary[ i ].key < ary[ (i - 1) / 2 ].key && (i - 1) / 2 >= 0)
			{
				swap(i, (i - 1) / 2);
				i = (i - 1) / 2;
			}
		}
		++size;
	}

    // return the element with the minimum key, remember to --size
    virtual char pop()
    {
    	if( isEmpty() )
    	{
    		cout << "ERROR: heap is empty." << endl;
    		return '0';
    	}

		int i = 0;
		char result = ary[i].element;
    	ary[ i ] = ary[ size - 1 ];

    	Node empty;
    	empty.key = 0;
    	empty.element = '0';
    	ary[ size - 1 ] = empty;
    	size--;
    	while( (ary[ i ].key > ary[2 * i + 1].key || ary[ i ].key > ary[2 * i + 2].key) && (2 * i) + 1 <= size - 1)
    	{
    		if(2 * i + 2 > size - 1)
    		{
    			swap(i, 2 * i + 1);
    			i = 2 * i + 1;
    			continue; //reach end
    		}
    		if(ary[ 2 * i + 1 ].key <= ary[ 2 * i + 2].key) //assume '<=' is acceptable
    		{
    			swap(i, 2 * i + 1);
    			i = 2 * i + 1;
    		}
    		else if(ary[2 * i + 1].key > ary[ 2 * i + 2 ].key)
    		{	
    			swap(i, 2 * i + 2);
    			i = 2 * i + 2;
    		}
    	}
    	return result;
    }
};
#endif