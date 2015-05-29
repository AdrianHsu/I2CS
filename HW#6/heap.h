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
			ary[ 0 ] = input;
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
		empty.key = -1;
		empty.element = '0';
		ary[ size - 1 ] = empty;
		size--;
		while(true)
		{
			if(2 * i + 1 > size - 1)
				break;
			if(2 * i + 1 == size - 1)
			{
				if(ary[ i ].key > ary[2 * i + 1].key)
					swap(i, 2 * i + 1);
				i = 2 * i + 1;
				break;
			}
			//in case '==' happens
			if(ary[ i ].key <= ary[2 * i + 1].key && ary[ i ].key <= ary[2 * i + 2].key)
				break;
			if(ary[ i ].key > ary[2 * i + 1].key && ary[ i ].key > ary[2 * i + 2].key)
			{
    			if(ary[ 2 * i + 1 ].key <= ary[ 2 * i + 2 ].key)
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
			else
			{
				if(ary[ i ].key > ary[2 * i + 1].key)
				{
					swap(i, 2 * i + 1);
					i = 2 * i + 1;
				}
				else
				{
					swap(i, 2 * i + 2);
					i = 2 * i + 2;
				}

			}
    	}
    	return result;
    }
};
#endif