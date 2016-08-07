// ===========================================================================
// About: MFC new generation data serialization class library.
// Author:	Zaqro Butskhrikidze
// Version: 1.0
// Started: 12/21/2010
// ===========================================================================

#include "stdafx.h"
#include "Serialize/Serializable.h"
#include "Path/Path.h"
#include "Utility/GrowableMemory.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//=============================================
//
//	class Serializable - Source code generate
//
//=============================================

bool
Serializable::GenerateSourceCodeInCSharp(_String& source, bool bGenerateNameSpace){
	// Determine variable infos of this and base class(es). {{
	int						nMainLoop	= 0;
	const AFX_VARINFOMAP*	pInfoMap	= GetVariableInfoMap();
	VariableInfo*			ppinfo[10];
	if( !pInfoMap )  return false;
	while( pInfoMap->pfnGetBaseVarInfoMap ){
		ppinfo[nMainLoop] = (VariableInfo*)pInfoMap->lpVarInfos;
		pInfoMap = (pInfoMap->pfnGetBaseVarInfoMap)();
		nMainLoop ++;
		}
	nMainLoop --;
	// }}

	CStringArray	arrLines;
	_String			sLine;
	int				nNameSpaceLineCt = 0;

	if( bGenerateNameSpace ){
		sLine = _T("using System;\r\n");
		arrLines.Add(sLine);
		nNameSpaceLineCt ++;
		sLine = _T("namespace AutoGeneratedObjects\r\n{\r\n");
		arrLines.Add(sLine);
		nNameSpaceLineCt ++;
		}

	while( nMainLoop > -1 ){
		VariableInfo*	info	= ppinfo[nMainLoop];
		int				nLoop	= 1;

		// Start class declaration.
		sLine.Format(_T("public class %s\r\n{\r\n"), (const TCHAR*)info->m_sAttributeName);
		arrLines.Add(sLine);
		// Constructor.
		sLine.Format(_T("public %s()\r\n{}\r\n"), (const TCHAR*)info->m_sAttributeName);
		arrLines.Add(sLine);
		// Members.
		sLine = _T("// Members.\r\n");
		arrLines.Add(sLine);

		while( info[nLoop].m_nOffset > 0 ){
			if( !info[nLoop].m_bComplexType ){ // Simple type.
				if( info[nLoop].m_bEnumerable ){
					ASSERT(FALSE);
					}
				else{ // Simple type.
					switch((int)info[nLoop].m_type)
					{
						case VariableType::VT_Bool:
							{
								sLine.Format(_T("public bool %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
								arrLines.Add(sLine);
								break;
							}
						case VariableType::VT_Int8:
							{
								sLine.Format(_T("public byte %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
								arrLines.Add(sLine);
								break;
							}
						case VariableType::VT_Int16:
							{
								sLine.Format(_T("public short %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
								arrLines.Add(sLine);
								break;
							}
						case VariableType::VT_Int32:
							{
								sLine.Format(_T("public int %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
								arrLines.Add(sLine);
								break;
							}
						case VariableType::VT_Int64:
							{
								sLine.Format(_T("public long %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
								arrLines.Add(sLine);
								break;
							}
						case VariableType::VT_Chips:
							{
								sLine.Format(_T("public decimal %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
								arrLines.Add(sLine);
								break;
							}
						case VariableType::VT_Float:
							{
								sLine.Format(_T("public float %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
								arrLines.Add(sLine);
								break;
							}
						case VariableType::VT_Double:
							{
								sLine.Format(_T("public double %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
								arrLines.Add(sLine);
								break;
							}
						case VariableType::VT_String:
							{
								sLine.Format(_T("public string %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
								arrLines.Add(sLine);
								break;
							}
						case VariableType::VT_DateTime:
						case VariableType::VT_Date:
						case VariableType::VT_Time:
							{
								sLine.Format(_T("public DateTime %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
								arrLines.Add(sLine);
								break;
							}
						}
					}
				}
			else{ // Complex type.
				int	nOffset = info[nLoop].m_nOffset;
				// Enumerable complex type.
				if( info[nLoop].m_bEnumerable ){ 
					sLine.Format(_T("public MFCEnumerableObject %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
					arrLines.Add(sLine);

					EnumerableObject<Serializable>* varPtr = (EnumerableObject<Serializable>*)&((LPBYTE)this)[nOffset];
					if( varPtr ){
						_String sAddinClassSrc;
						Serializable* pTempObj = varPtr->CreateSerializableObject();
						if( pTempObj->GenerateSourceCodeInCSharp(sAddinClassSrc, false) )
							arrLines.InsertAt(nNameSpaceLineCt, sAddinClassSrc);
						delete pTempObj;
						}
					}
				else{
					sLine.Format(_T("public %s %s {get; set;}\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName);
					arrLines.Add(sLine);

					void*	varPtr	= (void*)&((LPBYTE)this)[nOffset];
					Serializable* pObject = (Serializable*)varPtr;
					if( pObject ){
						_String sAddinClassSrc;
						if( pObject->GenerateSourceCodeInCSharp(sAddinClassSrc, false) )
							arrLines.InsertAt(nNameSpaceLineCt, sAddinClassSrc);
						}
					}
				}
			nLoop ++;
			}
		// Members.
		sLine = _T("}\r\n");
		arrLines.Add(sLine);
		nMainLoop --;
		}

	if( bGenerateNameSpace ){
		sLine = _T("}\r\n");
		arrLines.Add(sLine);
		}

	for(int i=0; i<arrLines.GetCount(); i++){
		source += arrLines[i];
		}
	return true;
	}

bool
Serializable::GenerateSourceCodeInAS3(StringToStringArray& arrSourceCodeByFileName, const TCHAR* pszPackage, const TCHAR* pszSerializeBasePackage){
	// Determine variable infos of this and base class(es). {{
	int						nMainLoop	= 0;
	const AFX_VARINFOMAP*	pInfoMap	= GetVariableInfoMap();
	VariableInfo*			ppinfo[10];
	if( !pInfoMap )  return false;
	while( pInfoMap->pfnGetBaseVarInfoMap ){
		ppinfo[nMainLoop] = (VariableInfo*)pInfoMap->lpVarInfos;
		pInfoMap = (pInfoMap->pfnGetBaseVarInfoMap)();
		nMainLoop ++;
		}
	nMainLoop --;
	// }}

	CStringArray	arrLines;
	_String			sLine, sBaseClassName = _T("Serializable");
	int				nNameSpaceLineCt = 0;
	
	while( nMainLoop > -1 ){
		VariableInfo*	info	= ppinfo[nMainLoop];
		int				nLoop	= 1;

		if( arrSourceCodeByFileName.KeyExists(info->m_sAttributeName) ){
			nMainLoop --;
			continue;
			}

		// Package header.
		sLine.Format(_T("package %s\r\n{"), pszPackage);
		arrLines.Add(sLine);
		sLine.Format( _T("\r\n\timport %s.*;\r\n\timport flash.utils.*;\r\n\r\n"), pszSerializeBasePackage);
		arrLines.Add(sLine);

		// Start class declaration.
		//public class BasePacket extends Serializable
		sLine.Format(_T("\tpublic class %s extends %s \r\n\t{\r\n"), (const TCHAR*)info->m_sAttributeName, sBaseClassName.GetBuffer());
		arrLines.Add(sLine);

		_String sClassVariables, sDeclareClassVariable;
		// Change base clase name.
		sBaseClassName = info->m_sAttributeName;

		while( info[nLoop].m_nOffset > 0 ){
			if( !info[nLoop].m_bComplexType ){ // Simple type.
				if( info[nLoop].m_bEnumerable ){
					ASSERT(FALSE);
					}
				else{ // Simple type.
					const TCHAR* pszAttrib = info[nLoop].m_sAttributeName;
					switch((int)info[nLoop].m_type){
						case VariableType::VT_Bool:{
							sLine.Format(_T("\t\tpublic var m_b%s:Boolean;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_b%s\", \"\", VariableType._Bool, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_Int8:{
							sLine.Format(_T("\t\tpublic var m_bt%s:int;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_bt%s\", \"\", VariableType._Int8, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_Int16:{
							sLine.Format(_T("\t\tpublic var m_sh%s:int;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_sh%s\", \"\", VariableType._Int16, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_Int32:{
							sLine.Format(_T("\t\tpublic var m_n%s:int;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_n%s\", \"\", VariableType._Int32, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_Int64:{
							sLine.Format(_T("\t\tpublic var m_n%s_low:int;\r\n\t\tpublic var m_n%s_high:int;\r\n"), pszAttrib, pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_n%s\", \"\", VariableType._Int64, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_Float:{
							sLine.Format(_T("\t\tpublic var m_f%s:Number;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_f%s\", \"\", VariableType._Float, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_Double:{
							sLine.Format(_T("\t\tpublic var m_d%s:Number;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_d%s\", \"\", VariableType._Double, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_String:{
							sLine.Format(_T("\t\tpublic var m_s%s:String;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_s%s\", \"\", VariableType._String, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_DateTime:{
							sLine.Format(_T("\t\tpublic var m_dtime%s:Date;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_dtime%s\", \"\", VariableType._DateTime, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_Date:{
							sLine.Format(_T("\t\tpublic var m_dt%s:Date;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_dt%s\", \"\", VariableType._Date, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_Time:{
							sLine.Format(_T("\t\tpublic var m_tm%s:Date;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_tm%s\", \"\", VariableType._Time, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						case VariableType::VT_Binary:{
							sLine.Format(_T("\t\tpublic var m_bin%s:ByteArray;\r\n"), pszAttrib);
							sClassVariables += sLine;
							sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_bin%s\", \"\", VariableType._Binary, false, false, false));\r\n"), pszAttrib);
							sDeclareClassVariable += sLine;
							break;
							}
						}
					}
				}
			else{ // Complex type.
				int	nOffset = info[nLoop].m_nOffset;
				// Enumerable complex type.
				if( info[nLoop].m_bEnumerable ){ 
					EnumerableObject<Serializable>* varPtr = (EnumerableObject<Serializable>*)&((LPBYTE)this)[nOffset];
					if( varPtr ){
						Serializable* pTempObj = varPtr->CreateSerializableObject();
						sLine.Format(_T("\t\tpublic var m_arr%s:Array //%s\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName, pTempObj->GetClassName().GetBuffer());
						sClassVariables += sLine;
						sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_arr%s\", \"%s.%s\", VariableType._Array, false, true, true));\r\n"), 
							(const TCHAR*)info[nLoop].m_sAttributeName, pszPackage, pTempObj->GetClassName().GetBuffer());
						sDeclareClassVariable += sLine;

						pTempObj->GenerateSourceCodeInAS3(arrSourceCodeByFileName, pszPackage, pszSerializeBasePackage);
						delete pTempObj;
						}
					}
				else{
					void*	varPtr	= (void*)&((LPBYTE)this)[nOffset];
					Serializable* pObject = (Serializable*)varPtr;
					if( pObject ){
						sLine.Format(_T("\t\tpublic var m_obj%s:%s\r\n"), (const TCHAR*)info[nLoop].m_sAttributeName, pObject->GetClassName().GetBuffer());
						sClassVariables += sLine;
						sLine.Format(_T("\t\t\tvarInfo.push(new VariableInfo(\"m_obj%s\", \"%s.%s\", VariableType._None, false, true, false));\r\n"), 
							(const TCHAR*)info[nLoop].m_sAttributeName, pszPackage, pObject->GetClassName().GetBuffer());
						sDeclareClassVariable += sLine;

						pObject->GenerateSourceCodeInAS3(arrSourceCodeByFileName, pszPackage, pszSerializeBasePackage);
						}
					}
				}
			nLoop ++;
			}

		// Class variables.
		arrLines.Add(sClassVariables);
		// Constructor.
		VariableInfo* pInfoPacketCode = GetVariableInfo(_T("Code"));
		if( pInfoPacketCode && pInfoPacketCode->m_type == VariableType::VT_Int16 && info->m_sAttributeName.CompareNoCase(_T("basepacket")) ){
			short nCode = *(short*)GetVariablePtr(_T("Code"));
			sLine.Format(_T("\r\n\t\tpublic function %s()\r\n\t\t{\r\n\t\t\tsuper();\r\n\t\t\tm_shCode = %d;\r\n\t\t}\r\n\r\n"), (const TCHAR*)info->m_sAttributeName, nCode);
			}
		else
			sLine.Format(_T("\r\n\t\tpublic function %s()\r\n\t\t{\r\n\t\t\tsuper();\r\n\t\t}\r\n\r\n"), (const TCHAR*)info->m_sAttributeName);
		arrLines.Add(sLine);
		// Start declaration of putVariableinfo method.
		sLine = _T("\t\toverride protected function   putVariableInfo(arrVarInfo:Array):void\r\n\t\t{\r\n\t\t\tsuper.putVariableInfo(arrVarInfo);\r\n\t\t\tvar varInfo:Vector.<VariableInfo> = new Vector.<VariableInfo>();\r\n");
		arrLines.Add(sLine);
		// Class variable declaration.
		arrLines.Add(sDeclareClassVariable);
		// Finish declaration of putVariableinfo method.
		sLine = _T("\t\t\tarrVarInfo.push(varInfo);\r\n\t\t}\r\n\r\n");
		arrLines.Add(sLine);
		// Finish package.
		sLine = _T("\t}\r\n}\r\n");
		arrLines.Add(sLine);

		_String sSourceCodePackage;
		for(int i=0; i<arrLines.GetCount(); i++)
			sSourceCodePackage += arrLines[i];
		arrLines.RemoveAll();

		// Add package.
		arrSourceCodeByFileName.Add(info->m_sAttributeName, sSourceCodePackage);

		nMainLoop --;
		}

	return true;
	}

bool
Serializable::GenerateSourceCodeInObjC(_String& source, bool bGenerateNameSpace){
	return false;
	}

bool
Serializable::GenerateSourceCodeInJS(_String& source, bool bGenerateNameSpace){
	return false;
	}
