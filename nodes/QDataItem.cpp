#include "QDataItem.h"
#include "CommonTreeWidget.h"
#include <QFileInfo>
#include <QFileIconProvider>
#include "utils_common.h"
#include <qstack.h>

QIcon QDataItem::mFolderIcon;
QIcon QDataItem::mFixedFolderIcon;
QIcon QDataItem::mFileIcon;

QDataItem::QDataItem(CommonTreeWidget *view)
  : QTreeWidgetItem(view, UserType)
  , mType(File)
  , mSize(0)
  , mItemCount(0)
  , mNodeCount(0)
  , mIsError(0)
  , mErrorDescription("")
  , mDataTrackMode(1)
{
}

QDataItem::QDataItem(QDataItem *parent)
  : QTreeWidgetItem(parent)
  , mType(File)
  , mSize(0)
  , mItemCount(0)
  , mNodeCount(0)
  , mIsError(0)
  , mErrorDescription("")
  , mDataTrackMode(1)
{
}


QDataItem * QDataItem::clone() const
{
  QDataItem *copy = nullptr;

  QStack<const QDataItem*> stack;
  QStack<QDataItem*> parentStack;
  stack.push(this);
  parentStack.push(nullptr);

  QDataItem *root = nullptr;
  const QDataItem *item = nullptr;
  QDataItem *parent = nullptr;
  while (!stack.isEmpty()) {
    item = stack.pop();
    parent = parentStack.pop();

    copy = new QDataItem(*item);
    if (!root)
      root = copy;

    if (parent) {
      parent->insertChild(0, copy);
    }

    for (int i = 0; i < item->childCount(); ++i) {
      stack.push(static_cast<QDataItem*>(item->child(i)));
      parentStack.push(copy);
    }
  }
  return root;
}

void QDataItem::SetType(ValueType type)
{
  mType = type;
  //if (File == mType) {
  //  setIcon(0, mFileIcon);
  //} else if (Folder == mType) {
  //  setIcon(0, mFolderIcon);
  //}
}

void QDataItem::AddDefaultIcon(const QPixmap &folderIconOn,
                               const QPixmap &folderIconOff,
                               const QPixmap &fixedFolderIconOn,
                               const QPixmap &fixedFolderIconOff,
                               const QPixmap &fileIcon)
{
  mFolderIcon.addPixmap(folderIconOn, QIcon::Normal, QIcon::On);
  mFolderIcon.addPixmap(folderIconOff, QIcon::Normal, QIcon::Off);
  mFixedFolderIcon.addPixmap(fixedFolderIconOn, QIcon::Normal, QIcon::On);
  mFixedFolderIcon.addPixmap(fixedFolderIconOff, QIcon::Normal, QIcon::Off);
  mFileIcon.addPixmap(fileIcon);
}

void QDataItem::SetDefaultIcon()
{
  if (QDataItem::Folder == mType) {
    setIcon(0, mFolderIcon);
  } else if (QDataItem::FixedFolder == mType) {
    setIcon(0, mFixedFolderIcon);
  } else if (QDataItem::File == mType) {
    setIcon(0, mFileIcon);
  }
}

void QDataItem::SetDataWithName(const QString &name)
{
  mName = name;
  mIsHidden = false;
  mIsHiddenExt = false;
  mPriority = 0;
  mDateAdded = QDateTime::currentDateTime();
  mDateCreated = mDateAdded;
  mDateModified = mDateAdded;
  SetDefaultIcon();
  setText(0, mName);
  setText(1, humanReadableSize(mSize));
  setText(2, mComment);
}

void QDataItem::SetData(const QString &path)
{
  QFileInfo fileinfo(path);
  fileinfo.setFile(fileinfo.absoluteFilePath());
  mName = fileinfo.fileName();
  mDateAdded = QDateTime::currentDateTime();
  if (0 == path.compare(mName)) {
    // it's a virtual new added item, not from filesystem.
    mFullPath = "";
    mDateCreated = mDateAdded;
    mDateModified = mDateAdded;
  } else {
    mFullPath = fileinfo.absoluteFilePath();
    mDateCreated = fileinfo.birthTime();
    mDateModified = fileinfo.lastModified();
  }

  mSize = fileinfo.size();
  mIsHidden = false;
  mIsHiddenExt = false;
  mPriority = 0;
  /*
  int size = ConfigurationPage::mSettings.value("NoChecksumFileSize", "32").toInt();
  if (ConfigurationPage::mSettings.value("CreateAndShowChecksum", true).toBool()
      && mSize <= size) {
    mChecksum = CalcChecksum(mFullPath);
  } else {
    mChecksum = "";
  }
  */
  mChecksum = "";
  mComment = "";
  QFileIconProvider iconprovider;
  QIcon icon = iconprovider.icon(fileinfo);
  setIcon(0, icon);
  setText(0, mName);
  setText(1, humanReadableSize(mSize));
  setText(2, mComment);
}

void QDataItem::SetDataAudio(const QString &path, qint64 data_time, const QString &comment)
{
    QFileInfo fileinfo(path);
    fileinfo.setFile(fileinfo.absoluteFilePath());
    mName = fileinfo.fileName();
    if (0 == path.compare(mName)) {
      mFullPath = "";
    } else {
      mFullPath = fileinfo.absoluteFilePath();
    }

    mSize = fileinfo.size();
    mIsHidden = false;
    mIsHiddenExt = false;
    mPriority = 0;
    mDateAdded = QDateTime::currentDateTime();
    mDateCreated = fileinfo.birthTime();
    mDateModified = fileinfo.lastModified();

    mComment = comment;
    mPlayTime = data_time;
    QFileIconProvider iconprovider;
    QIcon icon = iconprovider.icon(fileinfo);
    setIcon(0, icon);
    setText(0, mName);
    setText(1, humanReadableSize(mSize));
    setText(2, QDateTime::fromTime_t(mPlayTime).toUTC().toString("hh:mm:ss"));
    setText(3, mComment);
}

void QDataItem::SetData(ValueType type, const QString &path, const QString &name,
                        qint64 size, int item_count, int node_count)
{
  mType = type;
  if (File == type) {
    mFullPath = path;
    QFileInfo fileinfo(path);
    QFileIconProvider iconprovider;
    QIcon icon = iconprovider.icon(fileinfo);
    setIcon(0, icon);
  } else if (Folder == type) {
    mFullPath = path;
  }
  mName = name;
  mSize = size;
  mItemCount = item_count;
  mNodeCount = node_count;
  setText(0, mName);
  setText(1, humanReadableSize(mSize));
  setText(2, mComment);
}

void QDataItem::SetData(ValueType type, const QString &path, const QString &name,
                        qint64 size, int item_count, int node_count,
                        bool bHidden, bool bHiddenExt, int priority,
                        QDateTime date_added, QDateTime date_created, QDateTime date_modified,
                        const QString &checksum, const QString &comment)
{
  mIsHidden = bHidden;
  mIsHiddenExt = bHiddenExt;
  mPriority = priority;
  mDateAdded = date_added;
  mDateCreated = date_created;
  mDateModified = date_modified;
  mChecksum = checksum.toStdString().c_str();
  mComment = comment;
  SetData(type, path, name, size, item_count, node_count);
}

void QDataItem::SetDataLBA(const qint64 data_size)
{
    setText(1, QString::number(data_size));
}

void QDataItem::SetDataSize(const qint64 data_size,bool isExplorer)
{
  mSize = data_size;
  if(isExplorer==false){
      setText(1, humanReadableSize(mSize));
  }else{
      setText(2, humanReadableSize(mSize));
  }

}

void QDataItem::SetDataTime(const qint64 data_time)
{
  setText(2, QDateTime::fromTime_t(data_time).toUTC().toString("hh:mm:ss"));
}

QString QDataItem::GetDiskPath()
{
  QString disk_path;// = GetName();

  QDataItem *parent = static_cast<QDataItem*>(this->parent());

  while (parent != nullptr) {

      if(parent->GetType()==QDataItem::DataTrack)break;

      //We have changed it from slash to backslash. We keep everything backslash here.
      disk_path.insert(0, parent->GetName() + "//");
      parent = static_cast<QDataItem*>(parent->parent());

  }
 //We have changed it from slash to backslash. We keep everything backslash here.
  disk_path.insert(0, "//");
  return disk_path;
}

QString QDataItem::GetDiskFilePath()
{
  QString disk_path = GetName();

  QDataItem *parent = static_cast<QDataItem*>(this->parent());
  while (parent != nullptr) {
    if(parent->GetType()==QDataItem::DataTrack)break;
    //We have changed it from slash to backslash. We keep everything backslash here.
    disk_path.insert(0, parent->GetName() + "//");
    parent = static_cast<QDataItem*>(parent->parent());
  }
  //We have changed it from slash to backslash. We keep everything backslash here.
  disk_path.insert(0, "//");
  return disk_path;
}

bool QDataItem::DoValidate()
{
  if (File == mType) {
    QFileInfo fileinfo(mFullPath);
    if (fileinfo.exists()) {
      return true;
    } else {
      mIsError = true;
      mErrorDescription = "File not found";
      setText(2, mErrorDescription);
      return false;
    }
  } else {
    return true;
  }
}

QString QDataItem::ToXMLElementIndexFile(int depth)
{
  QString out = "";
  //QString tagName = item->data(0, Qt::UserRole).toString();
  if (QDataItem::Folder == mType) {
    //bool folded = !isExpanded();
    out += indent(depth)
        + "<folder name=" + escapedAttribute(text(0))
        + " size=" + escapedAttribute(QString::number(GetDataSize()))
        + " hidden=" + escapedAttribute(QString::number(GetHidden()))
        + " hiddenext=" + escapedAttribute(QString::number(GetHiddenExt()))
        + " priority=" + escapedAttribute(QString::number(GetPriority()))
        + " dateadded=" + escapedAttribute(GetDateAdded().toString())
        + " datecreated=" + escapedAttribute(GetDateCreated().toString())
        + " datemodified=" + escapedAttribute(GetDateModified().toString())
        + " comment=" + escapedAttribute(GetComment())
        + ">\n";

    for (int i = 0; i < childCount(); ++i)
      out += static_cast<QDataItem*>(child(i))->ToXMLElementIndexFile(depth + 1);


    out += indent(depth) + "</folder>\n";
  } else if (QDataItem::File == mType) {
    out += indent(depth) + "<file";
    //if (!item->text(0).isEmpty())
    out += " name=" + escapedAttribute(text(0))
        + " size=" + escapedAttribute(QString::number(GetDataSize()))
        //+ " path=" + escapedAttribute(GetFullPath())
        + " hidden=" + escapedAttribute(QString::number(GetHidden()))
        + " hiddenext=" + escapedAttribute(QString::number(GetHiddenExt()))
        + " priority=" + escapedAttribute(QString::number(GetPriority()))
        + " dateadded=" + escapedAttribute(GetDateAdded().toString())
        + " datecreated=" + escapedAttribute(GetDateCreated().toString())
        + " datemodified=" + escapedAttribute(GetDateModified().toString())
        + " checksum=" + escapedAttribute(GetChecksum())
        + " comment=" + escapedAttribute(GetComment());
    out += "/>\n";
  } else if (QDataItem::DataTrack == mType) {
    //bool folded = !isExpanded();
    out += indent(depth)
        + "<datatrack name=" + escapedAttribute(text(0))
        + " size=" + escapedAttribute(QString::number(GetDataSize()))
        + ">\n";

    for (int i = 0; i < childCount(); ++i)
      out += static_cast<QDataItem*>(child(i))->ToXMLElementIndexFile(depth + 1);


    out += indent(depth) + "</datatrack>\n";
  }
  return out;
}

QString QDataItem::ToXMLElement(int depth)
{
  QString out = "";
  //QString tagName = item->data(0, Qt::UserRole).toString();
  if (QDataItem::Folder == mType) {
    bool folded = !isExpanded();
    out += indent(depth)
        + "<folder name=" + escapedAttribute(text(0))
        + " size=" + escapedAttribute(QString::number(GetDataSize()))
        + " path=" + escapedAttribute(GetFullPath())
        + " item_count=" + escapedAttribute(QString::number(GetDataItemCount()))
        + " node_count=" + escapedAttribute(QString::number(GetDataNodeCount()))
        + " folded=\"" + (folded ? "yes" : "no") + "\""
        + " hidden=" + escapedAttribute(QString::number(GetHidden()))
        + " hiddenext=" + escapedAttribute(QString::number(GetHiddenExt()))
        + " priority=" + escapedAttribute(QString::number(GetPriority()))
        + " dateadded=" + escapedAttribute(GetDateAdded().toString())
        + " datecreated=" + escapedAttribute(GetDateCreated().toString())
        + " datemodified=" + escapedAttribute(GetDateModified().toString())
        + " comment=" + escapedAttribute(GetComment())
        + ">\n";

    for (int i = 0; i < childCount(); ++i)
      out += static_cast<QDataItem*>(child(i))->ToXMLElement(depth + 1);



    out += indent(depth) + "</folder>\n";
  } else if (QDataItem::File == mType) {
    out += indent(depth) + "<file";
    //if (!item->text(0).isEmpty())
    out += " name=" + escapedAttribute(text(0))
        + " size=" + escapedAttribute(QString::number(GetDataSize()))
        + " path=" + escapedAttribute(GetFullPath())
        + " hidden=" + escapedAttribute(QString::number(GetHidden()))
        + " hiddenext=" + escapedAttribute(QString::number(GetHiddenExt()))
        + " priority=" + escapedAttribute(QString::number(GetPriority()))
        + " dateadded=" + escapedAttribute(GetDateAdded().toString())
        + " datecreated=" + escapedAttribute(GetDateCreated().toString())
        + " datemodified=" + escapedAttribute(GetDateModified().toString())
        + " checksum=" + escapedAttribute(GetChecksum())
        + " comment=" + escapedAttribute(GetComment());
    out += "/>\n";
  } else if (QDataItem::DataTrack == mType) {
    bool folded = !isExpanded();
    out += indent(depth)
        + "<datatrack name=" + escapedAttribute(text(0))
        + " size=" + escapedAttribute(QString::number(GetDataSize()))
        + " item_count=" + escapedAttribute(QString::number(GetDataItemCount()))
        + " node_count=" + escapedAttribute(QString::number(GetDataNodeCount()))
        + " folded=\"" + (folded ? "yes" : "no")
        + "\">\n";

    for (int i = 0; i < childCount(); ++i)
      out += static_cast<QDataItem*>(child(i))->ToXMLElement(depth + 1);

    out += indent(depth) + "</datatrack>\n";
    //} else if (QDataItem::AudioTrack == mType) {
    //  bool folded = !isExpanded();
    //  out += indent(depth)
    //      + "<audiotrack name=" + escapedAttribute(text(0))
    //      + " size=" + escapedAttribute(QString::number(GetDataSize()))
    //      + " item_count=" + escapedAttribute(QString::number(GetDataItemCount()))
    //      + " folded=\"" + (folded ? "yes" : "no")
    //      + "\">\n";

    //  for (int i = 0; i < childCount(); ++i)
    //    out += ((QDataItem*)child(i))->ToXMLElement(depth + 1);

    //  out += indent(depth) + "</audiotrack>\n";
  }
  return out;
}

void QDataItem::FromXMLElement(const QString &qName, const QXmlAttributes &attributes)
{
  if (qName == "folder") {
    setFlags(flags() | Qt::ItemIsEditable);
    QString size = attributes.value("size");
    QString item_count = attributes.value("item_count");
    QString node_count = attributes.value("node_count");
    QString hidden = attributes.value("hidden");
    QString hiddenExt = attributes.value("hiddenext");
    QString priority = attributes.value("priority");
    QString dateadded = attributes.value("dateadded");
    QString datecreated = attributes.value("datecreated");
    QString datemodified = attributes.value("datemodified");
    SetData(QDataItem::Folder, attributes.value("path"), attributes.value("name"),
            size.toInt(), item_count.toInt(), node_count.toInt(),
            hidden.toInt(), hiddenExt.toInt(), priority.toInt(),
            QDateTime::fromString(dateadded), QDateTime::fromString(datecreated),
            QDateTime::fromString(datemodified), "", attributes.value("comment"));
    //setIcon(0, mFolderIcon);
    bool folded = (attributes.value("folded") != "no");
    setExpanded(!folded);
  } else if (qName == "file") {
    setFlags((flags() & (~Qt::ItemIsDropEnabled)) | Qt::ItemIsEditable);
    QString size = attributes.value("size");
    QString hidden = attributes.value("hidden");
    QString hiddenExt = attributes.value("hiddenext");
    QString priority = attributes.value("priority");
    QString dateadded = attributes.value("dateadded");
    QString datecreated = attributes.value("datecreated");
    QString datemodified = attributes.value("datemodified");
    SetData(QDataItem::File, attributes.value("path"),
            attributes.value("name"), size.toInt(), 1, 0,
            hidden.toInt(), hiddenExt.toInt(), priority.toInt(),
            QDateTime::fromString(dateadded), QDateTime::fromString(datecreated),
            QDateTime::fromString(datemodified), attributes.value("checksum"),
            attributes.value("comment"));
    DoValidate();
  } else if (qName == "datatrack") {
    QString size = attributes.value("size");
    QString item_count = attributes.value("item_count");
    QString node_count = attributes.value("node_count");
    SetData(QDataItem::DataTrack, QString(""), attributes.value("name"),
            size.toInt(), item_count.toInt(), node_count.toInt());
    bool folded = (attributes.value("folded") != "no");
    setExpanded(!folded);
  }
}

void QDataItem::ParseAndSetDateTime(const SFileEntry &info)
{
  SetDateAdded(ConvertDateTime(info.cCreationTime));
  SetDateCreated(ConvertDateTime(info.cCreationTime));
  SetDateModified(ConvertDateTime(info.cDateTime));
}

QString QDataItem::indent(int depth)
{
  const int IndentSize = 2;
  return QString(IndentSize * depth, ' ');
}

QString QDataItem::escapedText(const QString &str)
{
  QString result = str;
  result.replace("&", "&amp;");
  result.replace("<", "&lt;");
  result.replace(">", "&gt;");
  return result;
}

QString QDataItem::escapedAttribute(const QString &str)
{
  QString result = escapedText(str);
  result.replace("\"", "&quot;");
  result.prepend("\"");
  result.append("\"");
  return result;
}
