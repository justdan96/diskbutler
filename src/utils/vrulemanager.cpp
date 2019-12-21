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

#include "vrulemanager.h"

RuleManager::OptionID RuleManager::rule_AudioCD[] = {
  //Settings
  OPTION_SETTINGS_BURNPROOF,
  OPTION_SETTINGS_EJECT,
  OPTION_SETTINGS_SIMULATE,
  OPTION_SETTINGS_AUTOERASE,
  OPTION_SETTINGS_OPC,
  //Disk Types
  OPTION_DISKTYPES_CD,
  //Write Method
  OPTION_WRITEMETHOD_TRACKATONCE,
  OPTION_WRITEMETHOD_DISKATONCE,
  OPTION_WRITEMETHOD_DISKATONCE96,
};

RuleManager::OptionID RuleManager::rule_MixMode[] = {
  //Filesystems
  OPTION_FILESYSTEMS_ISO9660,
  OPTION_FILESYSTEMS_JOLIET,
  //specials
  OPTION_SPECIALS_ISOEXTINFO,
  //Mode
  OPTION_MODE_MODE1,
  OPTION_MODE_MODE2,
  //Filesysteme Extended
  OPTION_FILESYSTEMEXT_ISOLEVEL1,
  OPTION_FILESYSTEMEXT_ISOLEVEL2,
  OPTION_FILESYSTEMEXT_ISOLEVEL3,
  OPTION_FILESYSTEMEXT_ROMEO,
  OPTION_FILESYSTEMEXT_ALLOW_LONGISO_FILENAMES,
  OPTION_FILESYSTEMEXT_ALLOW_LONGJOLIET_FILENAMES,
  OPTION_FILESYSTEMEXT_ALLOW_LOWERCASE_FILENAMES,
  OPTION_FILESYSTEMEXT_ALLOW_MANY_DIRECTORIES,
  OPTION_FILESYSTEMEXT_ROCK_RIDGE,
  //Settings
  OPTION_SETTINGS_FINALIZE,
  OPTION_SETTINGS_BURNPROOF,
  OPTION_SETTINGS_VERIFY,
  OPTION_SETTINGS_EJECT,
  OPTION_SETTINGS_SIMULATE,
  OPTION_SETTINGS_PADDATATRACKS,
  OPTION_SETTINGS_AUTOERASE,
  OPTION_SETTINGS_OPC,
  //Disk Types
  OPTION_DISKTYPES_CD,
  //Write Method
  OPTION_WRITEMETHOD_TRACKATONCE,
  OPTION_WRITEMETHOD_DISKATONCE,
  OPTION_WRITEMETHOD_DISKATONCE96,
};

RuleManager::OptionID RuleManager::rule_VideoDVD[] = {
  //filesystems
  OPTION_FILESYSTEMS_ISO9660,
  OPTION_FILESYSTEMS_UDF102,
  //specials
  OPTION_SPECIALS_ISOEXTINFO,
  //Mode
  OPTION_MODE_MODE2,
  //Filesysteme Extended
  OPTION_FILESYSTEMEXT_ISOLEVEL1,
  OPTION_FILESYSTEMEXT_ISOLEVEL2,
  OPTION_FILESYSTEMEXT_ISOLEVEL3,
  //Settings
  OPTION_SETTINGS_BURNPROOF,
  OPTION_SETTINGS_VERIFY,
  OPTION_SETTINGS_EJECT,
  OPTION_SETTINGS_AUTOERASE,
  OPTION_SETTINGS_OPC,
  //Disk Types
  OPTION_DISKTYPES_DVD,
  //Write Method
  OPTION_WRITEMETHOD_DISKATONCE,
  OPTION_FILESYSTEMS_UDF,
};

RuleManager::OptionID RuleManager::rule_BlurayVideo[] = {
  //filesystems
  OPTION_FILESYSTEMS_UDF25,
  OPTION_FILESYSTEMS_UDF26,
  //specials
  OPTION_SPECIALS_AVCHD,
  //Settings
  OPTION_SETTINGS_BURNPROOF,
  OPTION_SETTINGS_VERIFY,
  OPTION_SETTINGS_EJECT,
  OPTION_SETTINGS_AUTOERASE,
  OPTION_SETTINGS_OPC,
  //Disk Types
  OPTION_DISKTYPES_DVD,
  OPTION_DISKTYPES_BD,
  //Write Method
  OPTION_WRITEMETHOD_DISKATONCE,
  OPTION_FILESYSTEMS_UDF,
};

RuleManager::OptionID RuleManager::rule_UDF[] = {
  //filesystems
  OPTION_FILESYSTEMS_UDF102,
  OPTION_FILESYSTEMS_UDF15,
  OPTION_FILESYSTEMS_UDF20,
  OPTION_FILESYSTEMS_UDF201,
  OPTION_FILESYSTEMS_UDF25,
  OPTION_FILESYSTEMS_UDF26,
  //specials
  OPTION_SPECIALS_BootCD_DVD_BD,
  OPTION_SPECIALS_AVCHD,
  //UDF
  OPTION_UDF_PARTITION,
  OPTION_UDF_WRITE_FILE_STREAM,
  //Mode
  OPTION_MODE_MODE1,
  OPTION_MODE_MODE2,
  //Settings
  OPTION_SETTINGS_FINALIZE,
  OPTION_SETTINGS_BURNPROOF,
  OPTION_SETTINGS_VERIFY,
  OPTION_SETTINGS_EJECT,
  OPTION_SETTINGS_SIMULATE,
  OPTION_SETTINGS_MULTISESSION,
  OPTION_SETTINGS_AUTOERASE,
  OPTION_SETTINGS_OPC,
  //Disk Types
  OPTION_DISKTYPES_DVD,
  OPTION_DISKTYPES_BD,
  OPTION_DISKTYPES_CD,
  //Write Method
  OPTION_WRITEMETHOD_DISKATONCE,
  OPTION_FILESYSTEMS_UDF,
};

RuleManager::OptionID RuleManager::rule_ISO[] = {
  //filesystems
  OPTION_FILESYSTEMS_ISO9660,
  OPTION_FILESYSTEMS_JOLIET,
  //specials
  OPTION_SPECIALS_ISOEXTINFO,
  OPTION_SPECIALS_BootCD_DVD_BD,
  //Mode
  OPTION_MODE_MODE1,
  OPTION_MODE_MODE2,
  //Filesysteme Extended
  OPTION_FILESYSTEMEXT_ISOLEVEL1,
  OPTION_FILESYSTEMEXT_ISOLEVEL2,
  OPTION_FILESYSTEMEXT_ISOLEVEL3,
  OPTION_FILESYSTEMEXT_ROMEO,
  OPTION_FILESYSTEMEXT_ALLOW_LONGISO_FILENAMES,
  OPTION_FILESYSTEMEXT_ALLOW_LONGJOLIET_FILENAMES,
  OPTION_FILESYSTEMEXT_ALLOW_LOWERCASE_FILENAMES,
  OPTION_FILESYSTEMEXT_ALLOW_MANY_DIRECTORIES,
  OPTION_FILESYSTEMEXT_ROCK_RIDGE,
  //Settings
  OPTION_SETTINGS_FINALIZE,
  OPTION_SETTINGS_BURNPROOF,
  OPTION_SETTINGS_VERIFY,
  OPTION_SETTINGS_EJECT,
  OPTION_SETTINGS_SIMULATE,
  OPTION_SETTINGS_MULTISESSION,
  OPTION_SETTINGS_PADDATATRACKS,
  OPTION_SETTINGS_AUTOERASE,
  OPTION_SETTINGS_OPC,
  //Disk Types
  OPTION_DISKTYPES_DVD,
  OPTION_DISKTYPES_BD,
  OPTION_DISKTYPES_CD,
  //Write Method
  OPTION_WRITEMETHOD_DISKATONCE,
};

RuleManager::OptionID RuleManager::rule_ISOUDF[] = {
  //filesystems
  OPTION_FILESYSTEMS_ISO9660,
  OPTION_FILESYSTEMS_JOLIET,
  OPTION_FILESYSTEMS_UDF102,
  OPTION_FILESYSTEMS_UDF15,
  OPTION_FILESYSTEMS_UDF20,
  OPTION_FILESYSTEMS_UDF201,
  OPTION_FILESYSTEMS_UDF25,
  OPTION_FILESYSTEMS_UDF26,
  //specials
  OPTION_SPECIALS_ISOEXTINFO,
  OPTION_SPECIALS_BootCD_DVD_BD,
  //UDF
  OPTION_UDF_PARTITION,
  OPTION_UDF_WRITE_FILE_STREAM,
  //Mode
  OPTION_MODE_MODE1,
  OPTION_MODE_MODE2,
  //Filesysteme Extended
  OPTION_FILESYSTEMEXT_ISOLEVEL1,
  OPTION_FILESYSTEMEXT_ISOLEVEL2,
  OPTION_FILESYSTEMEXT_ISOLEVEL3,
  OPTION_FILESYSTEMEXT_ROMEO,
  OPTION_FILESYSTEMEXT_ALLOW_LONGISO_FILENAMES,
  OPTION_FILESYSTEMEXT_ALLOW_LONGJOLIET_FILENAMES,
  OPTION_FILESYSTEMEXT_ALLOW_LOWERCASE_FILENAMES,
  OPTION_FILESYSTEMEXT_ALLOW_MANY_DIRECTORIES,
  OPTION_FILESYSTEMEXT_ROCK_RIDGE,
  //settings
  OPTION_SETTINGS_FINALIZE,
  OPTION_SETTINGS_BURNPROOF,
  OPTION_SETTINGS_VERIFY,
  OPTION_SETTINGS_EJECT,
  OPTION_SETTINGS_SIMULATE,
  OPTION_SETTINGS_MULTISESSION,
  OPTION_SETTINGS_PADDATATRACKS,
  OPTION_SETTINGS_AUTOERASE,
  OPTION_SETTINGS_OPC,
  //Disk Types
  OPTION_DISKTYPES_DVD,
  OPTION_DISKTYPES_BD,
  OPTION_DISKTYPES_CD,
  //Write Method
  OPTION_WRITEMETHOD_DISKATONCE,
  OPTION_FILESYSTEMS_UDF,
};

RuleManager::OptionID RuleManager::rule_VideoCD[] = {
  //filesystems
  OPTION_FILESYSTEMS_ISO9660,
  OPTION_FILESYSTEMS_JOLIET,
  //specials
  OPTION_SPECIALS_ISOEXTINFO,
  //Mode
  OPTION_MODE_MODE2,
  //Filesysteme Extended
  OPTION_FILESYSTEMEXT_ISOLEVEL1,
  //Settings
  OPTION_SETTINGS_FINALIZE,
  OPTION_SETTINGS_BURNPROOF,
  OPTION_SETTINGS_EJECT,
  OPTION_SETTINGS_SIMULATE,
  OPTION_SETTINGS_AUTOERASE,
  OPTION_SETTINGS_OPC,
  //Disk Types
  OPTION_DISKTYPES_CD,
  //Write Method
  OPTION_WRITEMETHOD_TRACKATONCE,
  OPTION_WRITEMETHOD_DISKATONCE,
  OPTION_WRITEMETHOD_DISKATONCE96,
};

RuleManager::OptionID RuleManager::rule_SuperVideoCD[] = {
  //filesystems
  OPTION_FILESYSTEMS_ISO9660,
  OPTION_FILESYSTEMS_JOLIET,
  //specials
  OPTION_SPECIALS_ISOEXTINFO,
  //Mode
  OPTION_MODE_MODE2,
  //Filesysteme Extended
  OPTION_FILESYSTEMEXT_ISOLEVEL1,
  //Settings
  OPTION_SETTINGS_FINALIZE,
  OPTION_SETTINGS_BURNPROOF,
  OPTION_SETTINGS_EJECT,
  OPTION_SETTINGS_SIMULATE,
  OPTION_SETTINGS_AUTOERASE,
  OPTION_SETTINGS_OPC,
  //Disk Types
  OPTION_DISKTYPES_CD,
  //Write Method
  OPTION_WRITEMETHOD_TRACKATONCE,
  OPTION_WRITEMETHOD_DISKATONCE,
  OPTION_WRITEMETHOD_DISKATONCE96,
};

RuleManager::Rule RuleManager::rules[] = {
  {TYPE_PROJECT_AUDIOCD, rule_AudioCD, sizeof(rule_AudioCD)/sizeof(OptionID)},
  {TYPE_PROJECT_MIXEDMODE, rule_MixMode, sizeof(rule_MixMode)/sizeof(OptionID)},
  {TYPE_PROJECT_VIDEODVD, rule_VideoDVD, sizeof(rule_VideoDVD)/sizeof(OptionID)},
  {TYPE_PROJECT_BLURAYVIDEO, rule_BlurayVideo, sizeof(rule_BlurayVideo)/sizeof(OptionID)},
  {TYPE_PROJECT_UDF, rule_UDF, sizeof(rule_UDF)/sizeof(OptionID)},
  {TYPE_PROJECT_ISO, rule_ISO, sizeof(rule_ISO)/sizeof(OptionID)},
  {TYPE_PROJECT_ISOUDF, rule_ISOUDF, sizeof(rule_ISOUDF)/sizeof(OptionID)},
  {TYPE_PROJECT_VIDEOCD, rule_VideoCD, sizeof(rule_VideoCD)/sizeof(OptionID)},
  {TYPE_PROJECT_SUPERVIDEO, rule_SuperVideoCD, sizeof(rule_SuperVideoCD)/sizeof(OptionID)},
};

QString RuleManager::rule_String[] = {
  //filesystems
  "OPTION_FILESYSTEMS_ISO9660",
  "OPTION_FILESYSTEMS_JOLIET",
  "OPTION_FILESYSTEMS_UDF102",
  "OPTION_FILESYSTEMS_UDF15",
  "OPTION_FILESYSTEMS_UDF20",
  "OPTION_FILESYSTEMS_UDF201",
  "OPTION_FILESYSTEMS_UDF25",
  "OPTION_FILESYSTEMS_UDF26",
  //specials
  "OPTION_SPECIALS_ISOEXTINFO",
  "OPTION_SPECIALS_BootCD_DVD_BD",
  "OPTION_SPECIALS_AVCHD",
  //UDF
  "OPTION_UDF_PARTITION",
  "OPTION_UDF_WRITE_FILE_STREAM",
  //mode
  "OPTION_MODE_MODE1",
  "OPTION_MODE_MODE2",
  //Filesysteme Extended
  "OPTION_FILESYSTEMEXT_ISOLEVEL1",
  "OPTION_FILESYSTEMEXT_ISOLEVEL2",
  "OPTION_FILESYSTEMEXT_ISOLEVEL3",
  "OPTION_FILESYSTEMEXT_ROMEO",
  "OPTION_FILESYSTEMEXT_ALLOW_LONGISO_FILENAMES",
  "OPTION_FILESYSTEMEXT_ALLOW_LONGJOLIET_FILENAMES",
  "OPTION_FILESYSTEMEXT_ALLOW_LOWERCASE_FILENAMES",
  "OPTION_FILESYSTEMEXT_ALLOW_MANY_DIRECTORIES",
  "OPTION_FILESYSTEMEXT_ROCK_RIDGE",
  //Settings
  "OPTION_SETTING_FINALIZE",
  "OPTION_SETTING_BURNPROOF",
  "OPTION_SETTING_VERIFY",
  "OPTION_SETTING_EJECT",
  "OPTION_SETTING_SIMULATE",
  "OPTION_SETTING_MULTISESSION",
  "OPTION_SETTING_PADDATATRACKS",
  "OPTION_SETTING_AUTOERASE",
  "OPTION_SETTINGS_OPC",
  //Disk Types
  "OPTION_DISKTYPES_DVD",
  "OPTION_DISKTYPES_BD",
  "OPTION_DISKTYPES_CD",
  //Write Method
  "OPTION_WRITEMETHOD_TRACKATONCE",
  "OPTION_WRITEMETHOD_DISKATONCE",
  "OPTION_WRITEMETHOD_DISKATONCE96",
  "OPTION_FILESYSTEMS_UDF",
};

RuleManager::Rule_Exception RuleManager::rule_Exception[] = {
    {OPTION_FILESYSTEMS_JOLIET, OPTION_SPECIALS_AVCHD},
    {OPTION_FILESYSTEMS_JOLIET, OPTION_UDF_PARTITION},
    {OPTION_FILESYSTEMS_JOLIET, OPTION_UDF_WRITE_FILE_STREAM},
    {OPTION_FILESYSTEMS_JOLIET, OPTION_FILESYSTEMEXT_ALLOW_LONGJOLIET_FILENAMES},
    {OPTION_FILESYSTEMS_UDF102, OPTION_SPECIALS_ISOEXTINFO},
    {OPTION_FILESYSTEMS_UDF102, OPTION_SPECIALS_AVCHD},
    {OPTION_FILESYSTEMS_UDF102, OPTION_UDF_PARTITION },
    {OPTION_FILESYSTEMS_UDF102, OPTION_UDF_WRITE_FILE_STREAM},
    {OPTION_FILESYSTEMS_UDF15, OPTION_SPECIALS_ISOEXTINFO},
    {OPTION_FILESYSTEMS_UDF15, OPTION_SPECIALS_AVCHD},
    {OPTION_FILESYSTEMS_UDF20, OPTION_SPECIALS_ISOEXTINFO},
    {OPTION_FILESYSTEMS_UDF20, OPTION_SPECIALS_AVCHD},
    {OPTION_FILESYSTEMS_UDF201, OPTION_SPECIALS_ISOEXTINFO},
    {OPTION_FILESYSTEMS_UDF201, OPTION_SPECIALS_AVCHD},
    {OPTION_FILESYSTEMS_UDF25, OPTION_SPECIALS_ISOEXTINFO},
    {OPTION_FILESYSTEMS_UDF26, OPTION_SPECIALS_ISOEXTINFO},
    {OPTION_MODE_MODE2, OPTION_DISKTYPES_DVD},
    {OPTION_MODE_MODE2, OPTION_DISKTYPES_BD}
};

bool RuleManager::IsOptionAllowed(ProjectType type, OptionID id)
{
  for (int i=0; i<sizeof(rules)/sizeof(Rule); i++) {
    if (rules[i].type == type && rules[i].arraySize > 0) {
      for (int j=0; j<rules[i].arraySize; j++) {
        if (id == rules[i].ruleArray[j]) {
          return true;
        }
      }
    }
  }
  return false;
}

int RuleManager::GetException(OptionID id1, OptionID id2)
{
  OptionID tempID1 = id1;
  OptionID tempID2 = id2;

  if (tempID1 > tempID2) {
    tempID1 = id2;
    tempID2 = id1;
  }

  for (int i=0; i<(int)(sizeof(rule_Exception)/sizeof(Rule_Exception)) && id1<=rule_Exception[i].id1; i++) {
    if (id1 == rule_Exception[i].id1 && id2 == rule_Exception[i].id2) {
      return -1;
    }
  }
  return 0;
}

QString RuleManager::GetOptionsStr(ProjectType type)
{

  QString str;
  for (int i=0; i<(int)(sizeof(rules)/sizeof(Rule)); i++) {
    if (rules[i].type == type && rules[i].arraySize > 0) {
      for (int j=0; j<rules[i].arraySize; j++) {
        str = str + rule_String[rules[i].ruleArray[j]] + ";";
      }
      break;
    }
  }
  return str;
}

QString RuleManager::GetProjectTypeStr(ProjectType type)
{
  QString str;
  switch (type) {
    case RuleManager::TYPE_PROJECT_OPEN:
      str += "Open";
      break;
    case RuleManager::TYPE_PROJECT_AUDIOCD:
      str += "AudioCD";
      break;
    case RuleManager::TYPE_PROJECT_MIXEDMODE:
      str += "MixedMode";
      break;
    case RuleManager::TYPE_PROJECT_VIDEODVD:
      str += "VideoDVD";
      break;
    case RuleManager::TYPE_PROJECT_BLURAYVIDEO:
      str += "BlurayVideo";
      break;
    case RuleManager::TYPE_PROJECT_UDF:
      str += "UDF";
      break;
    case RuleManager::TYPE_PROJECT_ISO:
      str += "ISO";
      break;
    case RuleManager::TYPE_PROJECT_ISOUDF:
      str += "ISO/UDF";
      break;
    case RuleManager::TYPE_PROJECT_VIDEOCD:
      str += "VideoCD";
      break;
    case RuleManager::TYPE_PROJECT_SUPERVIDEO:
      str += "SuperVideo";
      break;
    default:
      break;
  }

  return str;
}
