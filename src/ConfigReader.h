#pragma once

#ifndef _CONFIG_READER_H_
#define _CONFIG_READER_H_

#include<vector>
#include<string>
#include<cassert>

//.csv file reader
class CConfigReader {
public:
	typedef std::string path_type;
	typedef std::string cell_type;
	typedef std::vector<cell_type> row_type;
	typedef std::vector<row_type> table_type;
	typedef unsigned int size_type;
	
	CConfigReader():_initialized(false){}
	
	bool init(path_type path);

	//property
	bool initialized() const {
		return _initialized;
	}
	size_type size() const {
		return _table.size();
	}
	size_type rowCount() const {
		return _table.size();
	}
	size_type colCount() const {
		if( !initialized() ) return 0;
		if( !_table.size() ) return 0;
		return _table[0].size();
	}
	size_type colCount(int nRow) {
		if ( !initialized() ) return 0;
		if (nRow >= _table.size()) return 0;
		return _table[nRow].size();
	}
	row_type row(size_type r) const {
		if( r>=_table.size() ) return row_type();
		return _table[r];
	}
	cell_type cell(size_type r,size_type c) const {
		row_type current_row = row(r);
		if( c>=current_row.size() ) return cell_type();
		return current_row[c];
	}

private:
	table_type _table;
	bool _initialized;
};

#endif
