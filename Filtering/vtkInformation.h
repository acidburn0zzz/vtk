/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkInformation.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
// .NAME vtkInformation - Store vtkAlgorithm input/output information.
// .SECTION Description
// vtkInformation represents information and/or data for one input or
// one output of a vtkAlgorithm.  It maps from keys to values of
// several data types.  Instances of this class are collected in
// vtkInformationVector instances and passed to
// vtkAlgorithm::ProcessUpstreamRequest and
// vtkAlgorithm::ProcessDownstreamRequest calls.  The information and
// data referenced by the instance on a particular input or output
// define the request made to the vtkAlgorithm instance.

#ifndef __vtkInformation_h
#define __vtkInformation_h

#include "vtkObject.h"

class vtkDataObject;
class vtkExecutive;
class vtkInformationDataObjectKey;
class vtkInformationDataObjectVectorKey;
class vtkInformationExecutiveKey;
class vtkInformationInformationKey;
class vtkInformationInformationVectorKey;
class vtkInformationIntegerKey;
class vtkInformationIntegerVectorKey;
class vtkInformationInternals;
class vtkInformationKey;
class vtkInformationKeyToInformationFriendship;
class vtkInformationKeyVectorKey;
class vtkInformationStringKey;
class vtkInformationVector;

class VTK_FILTERING_EXPORT vtkInformation : public vtkObject
{
public:
  static vtkInformation *New();
  vtkTypeRevisionMacro(vtkInformation,vtkObject);
  void PrintSelf(ostream& os, vtkIndent indent);

  // Description:
  // Clear all information entries.
  void Clear();

  // Description:
  // Copy all information entries from the given vtkInformation
  // instance.  Any previously existing entries are removed.
  void Copy(vtkInformation* from);

  // Description:
  // Copy the key/value pair associated with the given key in the
  // given information object.
  void CopyEntry(vtkInformation* from, vtkInformationKey* key);

  // Description:
  // Use the given key to lookup a list of other keys in the given
  // information object.  The key/value pairs associated with these
  // other keys will be copied.
  void CopyEntries(vtkInformation* from, vtkInformationKeyVectorKey* key);

  // Description:
  // Get/Set an integer-valued entry.
  void Set(vtkInformationIntegerKey* key, int value);
  int Get(vtkInformationIntegerKey* key);
  void Remove(vtkInformationIntegerKey* key);
  int Has(vtkInformationIntegerKey* key);

  // Description:
  // Get/Set an integer-vector-valued entry.
  void Append(vtkInformationIntegerVectorKey* key, int value);
  void Set(vtkInformationIntegerVectorKey* key, int* value, int length);
  int* Get(vtkInformationIntegerVectorKey* key);
  void Get(vtkInformationIntegerVectorKey* key, int* value);
  int Length(vtkInformationIntegerVectorKey* key);
  void Remove(vtkInformationIntegerVectorKey* key);
  int Has(vtkInformationIntegerVectorKey* key);

  // Description:
  // Get/Set an InformationKey-vector-valued entry.
  void Append(vtkInformationKeyVectorKey* key, vtkInformationKey* value);
  void Set(vtkInformationKeyVectorKey* key, vtkInformationKey** value, int length);
  vtkInformationKey** Get(vtkInformationKeyVectorKey* key);
  void Get(vtkInformationKeyVectorKey* key, vtkInformationKey** value);
  int Length(vtkInformationKeyVectorKey* key);
  void Remove(vtkInformationKeyVectorKey* key);
  int Has(vtkInformationKeyVectorKey* key);

  // Description:
  // Get/Set a DataObject-vector-valued entry.
  void Append(vtkInformationDataObjectVectorKey* key, vtkDataObject* value);
  void Set(vtkInformationDataObjectVectorKey* key, vtkDataObject** value, int length);
  vtkDataObject** Get(vtkInformationDataObjectVectorKey* key);
  void Get(vtkInformationDataObjectVectorKey* key, vtkDataObject** value);
  int Length(vtkInformationDataObjectVectorKey* key);
  void Remove(vtkInformationDataObjectVectorKey* key);
  int Has(vtkInformationDataObjectVectorKey* key);

  // Description:
  // Get/Set a string-valued entry.
  void Set(vtkInformationStringKey* key, const char*);
  const char* Get(vtkInformationStringKey* key);
  void Remove(vtkInformationStringKey* key);
  int Has(vtkInformationStringKey* key);

  // Description:
  // Get/Set an entry storing another vtkInformation instance.
  void Set(vtkInformationInformationKey* key, vtkInformation*);
  vtkInformation* Get(vtkInformationInformationKey* key);
  void Remove(vtkInformationInformationKey* key);
  int Has(vtkInformationInformationKey* key);

  // Description:
  // Get/Set an entry storing a vtkInformationVector instance.
  void Set(vtkInformationInformationVectorKey* key, vtkInformationVector*);
  vtkInformationVector* Get(vtkInformationInformationVectorKey* key);
  void Remove(vtkInformationInformationVectorKey* key);
  int Has(vtkInformationInformationVectorKey* key);

  // Description:
  // Get/Set an entry storing a vtkDataObject instance.
  void Set(vtkInformationDataObjectKey* key, vtkDataObject*);
  vtkDataObject* Get(vtkInformationDataObjectKey* key);
  void Remove(vtkInformationDataObjectKey* key);
  int Has(vtkInformationDataObjectKey* key);

  // Description:
  // Get/Set an entry storing a vtkExecutive instance.
  void Set(vtkInformationExecutiveKey* key, vtkExecutive*);
  vtkExecutive* Get(vtkInformationExecutiveKey* key);
  void Remove(vtkInformationExecutiveKey* key);
  int Has(vtkInformationExecutiveKey* key);

  // Description:
  // Upcast the given key instance.
  vtkInformationKey* GetKey(vtkInformationDataObjectKey* key);
  vtkInformationKey* GetKey(vtkInformationDataObjectVectorKey* key);
  vtkInformationKey* GetKey(vtkInformationExecutiveKey* key);
  vtkInformationKey* GetKey(vtkInformationInformationKey* key);
  vtkInformationKey* GetKey(vtkInformationInformationVectorKey* key);
  vtkInformationKey* GetKey(vtkInformationIntegerKey* key);
  vtkInformationKey* GetKey(vtkInformationIntegerVectorKey* key);
  vtkInformationKey* GetKey(vtkInformationStringKey* key);
  vtkInformationKey* GetKey(vtkInformationKey* key);

  // Description:
  // Initiate garbage collection when a reference is removed.
  virtual void UnRegister(vtkObjectBase* o);

protected:
  vtkInformation();
  ~vtkInformation();

  // Get/Set a map entry directly through the vtkObjectBase instance
  // representing the value.  Used internally to manage the map.
  void SetAsObjectBase(vtkInformationKey* key, vtkObjectBase* value);
  vtkObjectBase* GetAsObjectBase(vtkInformationKey* key);

  // Internal implementation details.
  vtkInformationInternals* Internal;

  // Garbage collection support.
  virtual void ReportReferences(vtkGarbageCollector*);
  virtual void RemoveReferences();
  virtual void GarbageCollectionStarting();
  int GarbageCollecting;
private:
  //BTX
  friend class vtkInformationKeyToInformationFriendship;
  //ETX
private:
  vtkInformation(const vtkInformation&);  // Not implemented.
  void operator=(const vtkInformation&);  // Not implemented.
};

#endif
