/*
 *  DiskButler - a powerful CD/DVD/BD recording software tool for Linux, macOS and Windows.
 *  Copyright (c) 20019 Ingo Foerster (pixbytesl@gmail.com).
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License 3 as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License 3 for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef ZIMPORT_STRATEGY_FIXEDFOLDER_H
#define ZIMPORT_STRATEGY_FIXEDFOLDER_H

#include "zimport_strategy.h"
#include <QStringList>

class ZImportStrategyFixedFolder : public ZImportStrategy
{
public:
  ZImportStrategyFixedFolder(const QString &path, const QStringList &fixedfolders
                             , bool exclude_other_all = false, bool exclude_other_folder = false);
  ZImportStrategy::ImportError Check(const QString &root, const QString &path);
  ZImportStrategy::ImportError Check2(const QString &folder_name, const QString &path);
  QStringList GetFixedFolders() {return mFolderNames;}

private:
  QStringList mFolderNames;
  bool mExcludeOtherAll;
  bool mExcludeOtherFolder;
};

#endif // ZIMPORT_STRATEGY_FIXEDFOLDER_H
