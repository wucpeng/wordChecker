#ifndef __STRING_CHECKER_H__
#define __STRING_CHECKER_H__

#include "defines.h"
#include <string>
#include "string.h"
#include <queue>


/*
 * Implements with Aho-Corasick automation algorithm
 *
 * O(n) to replace string
 */
class StringChecker
{
private:

	static const int BRANCH_NUM_MAX = 256;

	typedef struct Node
	{
		uint16 	depth;
	    Node* 	next[BRANCH_NUM_MAX];
	    Node* 	fail;
	    Node()
	    {
	    	depth 	= 0;
	    	fail	= NULL;
	        memset(next, 0, sizeof(next));
	    }
	} Node;

	Node* root;

public:
	StringChecker();
	virtual ~StringChecker();

public:

	void AddPattern( const char* pat );

	// invoke build after all pattern added !
	void Build();

	// replace word with "***" where matches one of the patterns
	// return true if replace happened
	bool Replace( std::string& src );


	void Reset();

private:

	void DeleteTree( Node* node );
};


#endif
