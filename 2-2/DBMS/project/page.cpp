#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<fstream>

using namespace std;

class Relation
{
	public:
	
		string relationName;
		int num_cols, tuple_size, relationID;
		
		Relation(string relation, int relationId, int numCols, int tupleSize)
		{
		
			relationName = relation;
			relationID = relationId;
			num_cols = numCols;
			tuple_size = tupleSize;
			
		}

		Relation()
		{
			;
		}
};


class Page
{
	public:
	
	int pageID, relationID;
	vector < vector <int> > data;
	
	Page ()
	{
	}

	Page(int relationID, int pageID)
	{
		relationID = relationID;
		pageID = pageID;
	}

	
	void loadData ( Relation relationObj, int start_offset, int end_offset )
	{
		
	        /* This will fill the variable 'data' with data from the file name 
		 *  in relationObj starting from start_offset to end_offset.
		 */

		string file = relationObj.relationName;
		int num_cols = relationObj.num_cols;
		
		int value = 0;
		char ch;
		fstream fileptr (file.c_str(), ios::in);
		
		fileptr.seekg(start_offset, ios::beg);

		while ( !fileptr.eof() )
		{
		
			vector <int> tuple;
			for ( int i = 0; i < num_cols; i++ )
			{
				fileptr >> value;
				tuple.push_back(value);
			}
		
			data.push_back(tuple);
			long t = fileptr.tellg();
			if ( t - 1 == end_offset )
				break;
		
		}
		
		fileptr.close();
	
	}

};


class BufferManager
{
	public:
		int currentSize, maxSize; /* buffer sizes */
		vector <Page*> bufferPages; /* This will contain relation and index files pages*/	
		
		
		BufferManager ( int maxSize )
		{
			maxSize = maxSize; /* maximum number of pages that can
						 * be stored in the buffer
						 */
			currentSize = 0;

		}

		void resetCurrentSize()
		{
			currentSize = 0;
		}

		void putPage (Page *p)
		{
					
			if ( currentSize < maxSize )
			{
				bufferPages.push_back(p);
				currentSize++;
			}
			else
				;/*ERROR;*/

		}
		
		
};




class PageManager
{
	public:
		
		Relation relationObj;
		
		map <int, vector <int> > pageOffsets; /* The key will be pageid and 
 * the value will be a vector containing start offset and end offset of the data contained in that page.*/

		PageManager ( Relation relation )
		{
			relationObj = relation;
		}

		void storePageOffsets(int page_size)
		{
			/* This function will read the relation file and load page ids and
			 * their corresponding offsets into the map. 
			 */
			
			/* number of records in a page (NR) = floor(page_size/tuple_size)
			 * initial start_offset = 0
			 * end_offset = start_offset + NR * tuple_size - 1
			 * subsequent start_offset = previous page end_offset + 1
			 */
			;
		}
		

		void createPage ( Page *p, int page_id )			
		{

			/* It creates a page instance for given page_id 
			 * and loads the data into the page 'p'
			 */

			p = new Page(relationObj.relationID, page_id);
	
			/* do error checking */
			vector <int> offsets = pageOffsets[page_id];
			int start_offset = offsets[0];
			int end_offset = offsets[1];
 

			p->loadData(relationObj, start_offset, end_offset);
//			p->loadData(relationObj, 12, 36); // testing
			
			
		}


		void flushtoIndexFile (Page p)
		{
			/* This will flush the data in the page 'p' to the index
			 *  file. 
			 */
			;
		}
			
};


int main()
{

	/* testing */
	
	Relation *r = new Relation("temp.txt", 1, 3, 12);
	PageManager *pm = new PageManager (*r);
	Page *p;
	pm->createPage(p, 0);
	
}

