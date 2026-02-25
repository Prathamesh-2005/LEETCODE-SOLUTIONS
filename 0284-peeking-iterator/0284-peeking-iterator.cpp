/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
public:
    int ptr;
    int n;
    vector<int>vec;
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
	    // Initialize any member here.
	    // **DO NOT** save a copy of nums and manipulate it directly.
	    // You should only use the Iterator interface methods.
	    ptr=0;
        vec=nums;
        n=vec.size();
	}
	
    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if(ptr<n){
            return vec[ptr];
        }
        return -1;
	}
	
	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
	    if(ptr<n)
        {
            return vec[ptr++];
        }
        return ptr;
	}
	
	bool hasNext() const {
	    if(ptr<n)
        {
            return true;
        }
        return false;
	}
};