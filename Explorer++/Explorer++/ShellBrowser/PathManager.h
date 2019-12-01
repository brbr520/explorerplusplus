// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#pragma once

#include <list>

class PathManager
{
public:

	PathManager();

	int				GetNumBackPathsStored(void) const;
	int				GetNumForwardPathsStored(void) const;
	UINT			CreateHistoryPopupMenu(HWND,POINT *,BOOL);
	std::list<PIDLIST_ABSOLUTE>	GetBackHistory() const;
	std::list<PIDLIST_ABSOLUTE>	GetForwardHistory() const;

	void			StoreIdl(PCIDLIST_ABSOLUTE pidl);
	PIDLIST_ABSOLUTE	RetrievePath(int iIndex);
	PIDLIST_ABSOLUTE	RetrievePathWithoutUpdate(int iIndex);
	PIDLIST_ABSOLUTE	RetrieveAndValidateIdl(int iIndex);

private:

	#define DEFAULT_ALLOCATION	10

	/* Points one past the "current" path. */
	int m_iCurrent;

	/* Points one past the end of the valid
	paths. */
	int m_nTotal;

	/* Number of paths allocated.  */
	int m_nAllocated;

	void ShiftIdlArray(int iStart);

	PIDLIST_ABSOLUTE *ppidlList;
};