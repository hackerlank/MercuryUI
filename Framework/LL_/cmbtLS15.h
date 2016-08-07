/**** C/C++ constants and function definitions for LS15.DLL ****/
/****  (c) 1991,..,1999,2000,..,06,... combit GmbH, Konstanz, Germany  ****/
/****  [build of 2009-10-15 14:10:25] ****/

#ifndef _LS15_H /* include header only once */
#define _LS15_H

#if !defined(_LS15_DONT_INCLUDE_OLE2_H) && !defined(_RC_INVOKED_) && !defined(RC_INVOKED)
  #if defined(WIN32)
    #include <ole2.h>
  #endif
#endif

#ifndef EXPLICIT_TYPES
  #define EXPLICIT_TYPES
  #ifndef INT
    typedef int INT; /* you should comment this out if you have any problems with INT */
  #endif
  #ifndef CHAR
    typedef char CHAR; /* you should comment this out if you have any problems with CHAR */
  #endif
  typedef unsigned char UINT8;
  typedef unsigned short UINT16;
  typedef signed char INT8;
  typedef signed short INT16;
  #ifndef _BASETSD_H_ /* MSVC6 defines these itself in basetsd.h */
    typedef unsigned long UINT32;
    typedef signed long INT32;
  #endif
#endif

#if defined(WIN32) && (!defined(__BORLANDC__) || __BORLANDC__ >= 0x450) && !defined(_RC_INVOKED_) && !defined(RC_INVOKED)
 #include <tchar.h>    /* for wide char support - comment this out if you have no 'tchar.h' */
#endif

#ifndef DLLPROC
  #define DLLPROC WINAPI
#endif
#ifndef DLLCPROC
  #define DLLCPROC WINAPIV
#endif

#if defined(__COMBIT__) && defined(_LS_)
  #define CMBT_LS_WINAPI // __declspec(dllexport)
#else
  #define CMBT_LS_WINAPI DECLSPEC_IMPORT
#endif
#if defined(__COMBIT__) && defined(__lib_)
	#pragma message("WRN: including header file in library. Is that intentional?")
#endif

#ifndef CMBTLANG_DEFAULT
 #define CMBTLANG_DEFAULT    -1
 #define CMBTLANG_GERMAN      0
 #define CMBTLANG_ENGLISH     1
 #define CMBTLANG_ARABIC      2
 #define CMBTLANG_AFRIKAANS   3
 #define CMBTLANG_ALBANIAN    4
 #define CMBTLANG_BASQUE      5
 #define CMBTLANG_BULGARIAN   6
 #define CMBTLANG_BYELORUSSIAN 7
 #define CMBTLANG_CATALAN     8
 #define CMBTLANG_CHINESE     9
 #define CMBTLANG_CROATIAN    10
 #define CMBTLANG_CZECH       11
 #define CMBTLANG_DANISH      12
 #define CMBTLANG_DUTCH       13
 #define CMBTLANG_ESTONIAN    14
 #define CMBTLANG_FAEROESE    15
 #define CMBTLANG_FARSI       16
 #define CMBTLANG_FINNISH     17
 #define CMBTLANG_FRENCH      18
 #define CMBTLANG_GREEK       19
 #define CMBTLANG_HEBREW      20
 #define CMBTLANG_HUNGARIAN   21
 #define CMBTLANG_ICELANDIC   22
 #define CMBTLANG_INDONESIAN  23
 #define CMBTLANG_ITALIAN     24
 #define CMBTLANG_JAPANESE    25
 #define CMBTLANG_KOREAN      26
 #define CMBTLANG_LATVIAN     27
 #define CMBTLANG_LITHUANIAN  28
 #define CMBTLANG_NORWEGIAN   29
 #define CMBTLANG_POLISH      30
 #define CMBTLANG_PORTUGUESE  31
 #define CMBTLANG_ROMANIAN    32
 #define CMBTLANG_RUSSIAN     33
 #define CMBTLANG_SLOVAK      34
 #define CMBTLANG_SLOVENIAN   35
 #define CMBTLANG_SERBIAN     36
 #define CMBTLANG_SPANISH     37
 #define CMBTLANG_SWEDISH     38
 #define CMBTLANG_THAI        39
 #define CMBTLANG_TURKISH     40
 #define CMBTLANG_UKRAINIAN   41
 #define CMBTLANG_CHINESE_TRADITIONAL   	 48
 #define CMBTLANG_PORTUGUESE_BRAZILIAN   	129
 #define CMBTLANG_SPANISH_COLOMBIA  		130
 #define CMBTLANG_UNSPECIFIED	255
#endif

/*--- type declarations ---*/

#ifndef _PCRECT
  #define _PCRECT                        const RECT FAR *
#endif

#ifndef _PRECT
  #define _PRECT                         RECT FAR *
#endif

#ifndef HLLSTG
  #define HLLSTG                         UINT_PTR
#endif

#ifndef HSTG
  #define HSTG                           UINT_PTR
#endif

#ifndef PHGLOBAL
  #define PHGLOBAL                       HGLOBAL FAR *
#endif

#ifndef HLSCNVJOB
  #define HLSCNVJOB                      UINT_PTR
#endif

#ifndef HLSMAILJOB
  #define HLSMAILJOB                     UINT_PTR
#endif

#ifndef _LPCWORD
  #define _LPCWORD                       const UINT16 FAR *
#endif

#ifndef PSTREAM
  #define PSTREAM                        IStream FAR *
#endif

#ifndef PCSCDIOOPTIONS
  #define PCSCDIOOPTIONS                 const scDIOOptions FAR *
#endif

#ifndef _PIEnumString
  #define _PIEnumString                  IEnumString FAR *
#endif

#ifndef _PPIEnumString
  #define _PPIEnumString                 IEnumString FAR * FAR *
#endif

#ifndef _PILLPreviewFileSystem
  #define _PILLPreviewFileSystem         ILLPreviewFileSystem FAR *
#endif

#ifndef PSCSTORAGEOPENINFO
  #define PSCSTORAGEOPENINFO             const scStorageOpenInfo FAR *
#endif


/*--- constant declarations ---*/

#define LL_ERR_STG_NOSTORAGE           (-1000               )
#define LL_ERR_STG_BADVERSION          (-1001               )
#define LL_ERR_STG_READ                (-1002               )
#define LL_ERR_STG_WRITE               (-1003               )
#define LL_ERR_STG_UNKNOWNSYSTEM       (-1004               )
#define LL_ERR_STG_BADHANDLE           (-1005               )
#define LL_ERR_STG_ENDOFLIST           (-1006               )
#define LL_ERR_STG_BADJOB              (-1007               )
#define LL_ERR_STG_ACCESSDENIED        (-1008               )
#define LL_ERR_STG_BADSTORAGE          (-1009               )
#define LL_ERR_STG_CANNOTGETMETAFILE   (-1010               )
#define LL_ERR_STG_OUTOFMEMORY         (-1011               )
#define LL_ERR_STG_SEND_FAILED         (-1012               )
#define LL_ERR_STG_DOWNLOAD_PENDING    (-1013               )
#define LL_ERR_STG_DOWNLOAD_FAILED     (-1014               )
#define LL_ERR_STG_WRITE_FAILED        (-1015               )
#define LL_ERR_STG_UNEXPECTED          (-1016               )
#define LL_ERR_STG_CANNOTCREATEFILE    (-1017               )
#define LL_ERR_STG_UNKNOWN_CONVERTER   (-1018               )
#define LL_ERR_STG_INET_ERROR          (-1019               )
#define LL_WRN_STG_UNFAXED_PAGES       (-1100               )
#define LS_OPTION_HAS16BITPAGES        (200                 ) /* has job 16 bit pages? */
#define LS_OPTION_BOXTYPE              (201                 ) /* wait meter box type */
#define LS_OPTION_UNITS                (203                 ) /* LL_UNITS_INCH_DIV_100 or LL_UNITS_MM_DIV_10 */
#define LS_OPTION_PRINTERCOUNT         (204                 ) /* number of printers (1 or 2) */
#define LS_OPTION_ISSTORAGE            (205                 ) /* returns whether file is STORAGE or COMPAT4 */
#define LS_OPTION_EMFRESOLUTION        (206                 ) /* EMFRESOLUTION used to print the file */
#define LS_OPTION_JOB                  (207                 ) /* returns current job number */
#define LS_OPTION_TOTALPAGES           (208                 ) /* differs from GetPageCount() if print range in effect */
#define LS_OPTION_PAGESWITHFAXNUMBER   (209                 )
#define LS_OPTION_HASINPUTOBJECTS      (210                 )
#define LS_OPTION_HASFORCEDINPUTOBJECTS (211                 )
#define LS_OPTION_INPUTOBJECTSFINISHED (212                 )
#define LS_OPTION_HASHYPERLINKS        (213                 )
#define LS_OPTION_PAGENUMBER           (0                   ) /* page number of current page */
#define LS_OPTION_COPIES               (1                   ) /* number of copies (same for all pages at the moment) */
#define LS_OPTION_PRN_ORIENTATION      (2                   ) /* orientation (DMORIENT_LANDSCAPE, DMORIENT_PORTRAIT) */
#define LS_OPTION_PHYSPAGE             (3                   ) /* is page "physical page" oriented? */
#define LS_OPTION_PRN_PIXELSOFFSET_X   (4                   ) /* this and the following values are */
#define LS_OPTION_PRN_PIXELSOFFSET_Y   (5                   ) /* values of the printer that the preview was */
#define LS_OPTION_PRN_PIXELS_X         (6                   ) /* created on! */
#define LS_OPTION_PRN_PIXELS_Y         (7                   )
#define LS_OPTION_PRN_PIXELSPHYSICAL_X (8                   )
#define LS_OPTION_PRN_PIXELSPHYSICAL_Y (9                   )
#define LS_OPTION_PRN_PIXELSPERINCH_X  (10                  )
#define LS_OPTION_PRN_PIXELSPERINCH_Y  (11                  )
#define LS_OPTION_PRN_INDEX            (12                  ) /* printer index of the page (0/1) */
#define LS_OPTION_PRN_PAPERTYPE        (13                  )
#define LS_OPTION_PRN_PAPERSIZE_X      (14                  )
#define LS_OPTION_PRN_PAPERSIZE_Y      (15                  )
#define LS_OPTION_PRN_FORCE_PAPERSIZE  (16                  )
#define LS_OPTION_STARTNEWSHEET        (17                  )
#define LS_OPTION_ISSUEINDEX           (18                  )
#define LS_OPTION_PROJECTNAME          (100                 ) /* name of the original project (not page dependent) */
#define LS_OPTION_JOBNAME              (101                 ) /* name of the job (WindowTitle of LlPrintWithBoxStart()) (not page dependent) */
#define LS_OPTION_PRTNAME              (102                 ) /* deprecated! */
#define LS_OPTION_PRTDEVICE            (103                 ) /* printer device ("HP Laserjet 4L") */
#define LS_OPTION_PRTPORT              (104                 ) /* deprecated! */
#define LS_OPTION_USER                 (105                 ) /* user string (not page dependent) */
#define LS_OPTION_CREATION             (106                 ) /* creation date (not page dependent) */
#define LS_OPTION_CREATIONAPP          (107                 ) /* creation application (not page dependent) */
#define LS_OPTION_CREATIONDLL          (108                 ) /* creation DLL (not page dependent) */
#define LS_OPTION_CREATIONUSER         (109                 ) /* creation user and computer name (not page dependent) */
#define LS_OPTION_FAXPARA_QUEUE        (110                 ) /* NYI */
#define LS_OPTION_FAXPARA_RECIPNAME    (111                 ) /* NYI */
#define LS_OPTION_FAXPARA_RECIPNUMBER  (112                 ) /* NYI */
#define LS_OPTION_FAXPARA_SENDERNAME   (113                 ) /* NYI */
#define LS_OPTION_FAXPARA_SENDERCOMPANY (114                 ) /* NYI */
#define LS_OPTION_FAXPARA_SENDERDEPT   (115                 ) /* NYI */
#define LS_OPTION_FAXPARA_SENDERBILLINGCODE (116                 ) /* NYI */
#define LS_OPTION_FAX_AVAILABLEQUEUES  (118                 ) /* NYI, nPageIndex=1 */
#define LS_OPTION_PRINTERALIASLIST     (119                 ) /* alternative printer list (taken from project) */
#define LS_OPTION_PRTDEVMODE           (120                 ) /* r/o, DEVMODEW structure, to be used with the LlConvertXxxx API */
#define LS_OPTION_USED_PRTDEVICE       (121                 ) /* r/o, printer name that would actually be used */
#define LS_OPTION_USED_PRTDEVMODE      (122                 ) /* r/o, DEVMODEW structure, to be used with the LlConvertXxxx API */
#define LS_PRINTFLAG_FIT               (0x00000001          )
#define LS_PRINTFLAG_STACKEDCOPIES     (0x00000002          ) /* n times page1, n times page2, ... (else n times (page 1...x)) */
#define LS_PRINTFLAG_TRYPRINTERCOPIES  (0x00000004          ) /* first try printer copies, then simulated ones... */
#define LS_PRINTFLAG_SHOWDIALOG        (0x00000008          )
#define LS_PRINTFLAG_METER             (0x00000010          )
#define LS_PRINTFLAG_ABORTABLEMETER    (0x00000020          )
#define LS_PRINTFLAG_METERMASK         (0x00000070          ) /* allows 7 styles of abort boxes... */
#define LS_PRINTFLAG_USEDEFPRINTERIFNULL (0x00000080          )
#define LS_PRINTFLAG_FAX               (0x00000100          )
#define LS_VIEWERCONTROL_QUERY_CHARWIDTH (1                   ) /* sent in wParam using LsGetViewerControlDefaultMessage() (return: 1 for SBCS, 2 for Unicode) */
#define LS_VIEWERCONTROL_CLEAR         (WM_USER+1           )
#define LS_VIEWERCONTROL_SET_HANDLE_EX (WM_USER+2           ) /* wParam = HANDLE (NULL for RELEASE), lParam = internal struct handle; */
#define LS_VIEWERCONTROL_SET_HANDLE    (WM_USER+3           ) /* wParam = HANDLE (NULL for RELEASE) */
#define LS_VIEWERCONTROLSETHANDLEFLAG_ADD (0x0100              )
#define LS_VIEWERCONTROLSETHANDLEFLAG_DELETE_ON_CLOSE (0x0200              )
#define LS_VIEWERCONTROL_GET_HANDLE    (WM_USER+4           ) /* lParam = HANDLE (NULL for none) */
#define LS_VIEWERCONTROL_SET_FILENAME  (WM_USER+5           ) /* lParam = LPCTSTR pszFilename (NULL for RELEASE), wParam = options */
#define LS_STGFILEOPEN_READONLY        (0x00000000          )
#define LS_STGFILEOPEN_READWRITE       (0x00000001          )
#define LS_STGFILEOPEN_FORCE_NO_READWRITE (0x00000002          ) /* never open read-write, even if formula elements are present! */
#define LS_STGFILEOPEN_DELETE_ON_CLOSE (0x00000004          )
#define LS_STGFILEOPENFLAG_ADD         (0x00000100          )
#define LS_VIEWERCONTROL_SET_OPTION    (WM_USER+6           )
#define LS_OPTION_MESSAGE              (0                   ) /* communication message */
#define LS_OPTION_PRINTERASSIGNMENT    (1                   ) /* set BEFORE setting the storage handle/filename! */
#define LS_PRNASSIGNMENT_USEDEFAULT    (0x00000000          )
#define LS_PRNASSIGNMENT_ASKPRINTERIFNEEDED (0x00000001          )
#define LS_PRNASSIGNMENT_ASKPRINTERALWAYS (0x00000002          )
#define LS_PRNASSIGNMENT_ALWAYSUSEDEFAULT (0x00000003          ) /* default */
#define LS_OPTION_TOOLBAR              (2                   ) /* TRUE to force viewer control to display a toolbar, FALSE otherwise (def: FALSE) */
#define LS_OPTION_SKETCHBAR            (3                   ) /* TRUE to force viewer control to display a sketch bar (def: TRUE) */
#define LS_OPTION_SKETCHBARWIDTH       (4                   ) /* TRUE to force viewer control to display a sketch bar (def: 50) */
#define LS_OPTION_TOOLBARSTYLE         (5                   ) /* default: LS_OPTION_TOOLBARSTYLE_STANDARD, set BEFORE LS_OPTION_TOOLBAR to TRUE! */
#define LS_OPTION_TOOLBARSTYLE_STANDARD (0                   ) /* OFFICE97 alike style */
#define LS_OPTION_TOOLBARSTYLE_OFFICEXP (1                   ) /* DOTNET/OFFICE_XP alike style */
#define LS_OPTION_TOOLBARSTYLE_OFFICE2003 (2                   )
#define LS_OPTION_TOOLBARSTYLEMASK     (0x0f                )
#define LS_OPTION_TOOLBARSTYLEFLAG_GRADIENT (0x80                ) /* starting with XP, use gradient style */
#define LS_OPTION_CODEPAGE             (7                   ) /* lParam = codepage for MBCS aware string operations - set it if the system default is not applicable */
#define LS_OPTION_SAVEASFILEPATH       (8                   ) /* w/o, lParam = "SaveAs" default filename (LPCTSTR!) */
#define LS_OPTION_USERDATA             (9                   ) /* for LS_VIEWERCONTROL_SET_NTFYCALLBACK */
#define LS_OPTION_BGCOLOR              (10                  ) /* background color */
#define LS_OPTION_ASYNC_DOWNLOAD       (11                  ) /* download is ASYNC (def: TRUE) */
#define LS_OPTION_LANGUAGE             (12                  ) /* CMBTLANG_xxx or -1 for ThreadLocale */
#define LS_OPTION_ASSUME_TEMPFILE      (13                  ) /* viewer assumes that the LL file is a temp file, so data can not be saved into it */
#define LS_OPTION_IOLECLIENTSITE       (14                  ) /* internal use */
#define LS_OPTION_TOOLTIPS             (15                  ) /* lParam = flag value */
#define LS_OPTION_AUTOSAVE             (16                  ) /* lParam = (BOOL)bAutoSave */
#define LS_OPTION_CHANGEDFLAG          (17                  ) /* lParam = flag value */
#define LS_OPTION_SHOW_UNPRINTABLE_AREA (18                  ) /* lParam = flags, default: TRUE */
#define LS_OPTION_NOUIRESET            (19                  ) /* lParam = flags, default: TRUE */
#define LS_OPTION_NAVIGATIONBAR        (20                  ) /* TRUE to force viewer control to display a sketch bar (def: TRUE) */
#define LS_OPTION_NAVIGATIONBARWIDTH   (21                  ) /* TRUE to force viewer control to display a sketch bar (def: 50) */
#define LS_OPTION_IN_PREVIEWPANE       (22                  ) /* TRUE to disable unneeded message boxes */
#define LS_OPTION_IN_LLVIEWER          (23                  ) /* internal */
#define LS_OPTION_TABBARSTYLE          (24                  )
#define LS_OPTION_TABBARSTYLE_STANDARD (0                   )
#define LS_OPTION_TABBARSTYLE_OFFICEXP (1                   )
#define LS_OPTION_TABBARSTYLE_OFFICE2003 (2                   )
#define LS_OPTION_DESIGNERPREVIEW      (25                  )
#define LS_VIEWERCONTROL_GET_OPTION    (WM_USER+7           )
#define LS_VIEWERCONTROL_QUERY_ENDSESSION (WM_USER+8           )
#define LS_VIEWERCONTROL_GET_ZOOM      (WM_USER+9           )
#define LS_VIEWERCONTROL_SET_ZOOM      (WM_USER+10          ) /* wParam = factor (lParam = 1 if in percent) */
#define LS_VIEWERCONTROL_GET_ZOOMED    (WM_USER+11          ) /* TRUE if zoomed */
#define LS_VIEWERCONTROL_POP_ZOOM      (WM_USER+12          )
#define LS_VIEWERCONTROL_RESET_ZOOM    (WM_USER+13          )
#define LS_VIEWERCONTROL_SET_ZOOM_TWICE (WM_USER+14          )
#define LS_VIEWERCONTROL_SET_PAGE      (WM_USER+20          ) /* wParam = page# (0..n-1) */
#define LS_VIEWERCONTROL_GET_PAGE      (WM_USER+21          )
#define LS_VIEWERCONTROL_GET_PAGECOUNT (WM_USER+22          )
#define LS_VIEWERCONTROL_GET_PAGECOUNT_FAXPAGES (WM_USER+23          )
#define LS_VIEWERCONTROL_GET_JOB       (WM_USER+24          )
#define LS_VIEWERCONTROL_GET_JOBPAGEINDEX (WM_USER+25          )
#define LS_VIEWERCONTROL_GET_METAFILE  (WM_USER+26          ) /* wParam = page#, for IMMEDIATE use (will be released by LS DLL at some undefined time!) */
#define LS_VIEWERCONTROL_GET_ENABLED   (WM_USER+27          ) /* wParam = ID */
#define LS_VCITEM_SEARCH_FIRST         (0                   )
#define LS_VCITEM_SEARCH_NEXT          (1                   )
#define LS_VCITEM_SEARCH_PREV          (2                   )
#define LS_VCITEM_SEARCHFLAG_CASEINSENSITIVE (0x8000              )
#define LS_VCITEM_SAVE_AS_FILE         (3                   )
#define LS_VCITEM_SEND_AS_MAIL         (4                   )
#define LS_VCITEM_SEND_AS_FAX          (5                   )
#define LS_VCITEM_PRINT_ONE            (6                   )
#define LS_VCITEM_PRINT_ALL            (7                   )
#define LS_VCITEM_PAGENUMBER           (8                   )
#define LS_VCITEM_ZOOM                 (9                   )
#define LS_VCITEM_THEATERMODE          (10                  )
#define LS_VCITEM_PREVSTG              (11                  )
#define LS_VCITEM_NEXTSTG              (12                  )
#define LS_VIEWERCONTROL_GET_SEARCHSTATE (WM_USER+28          ) /* returns TRUE if search in progress */
#define LS_VIEWERCONTROL_SEARCH        (WM_USER+29          ) /* wParam = BOOL(bCaseSens), lParam=SearchText (NULL to stop) */
#define LS_VIEWERCONTROL_GET_ENABLED_SEARCHPREV (WM_USER+30          )
#define LS_VIEWERCONTROL_PRINT_CURRENT (WM_USER+31          ) /* wParam = 0 (default printer), 1 (with printer selection) */
#define LS_VIEWERCONTROL_PRINT_ALL     (WM_USER+32          ) /* wParam = 0 (default printer), 1 (with printer selection) */
#define LS_VIEWERCONTROL_PRINT_TO_FAX  (WM_USER+33          )
#define LS_VIEWERCONTROL_UPDATE_TOOLBAR (WM_USER+35          ) /* if LS_OPTION_TOOLBAR is TRUE */
#define LS_VIEWERCONTROL_GET_TOOLBAR   (WM_USER+36          ) /* if LS_OPTION_TOOLBAR is TRUE, returns window handle of toolbar */
#define LS_VIEWERCONTROL_SAVE_TO_FILE  (WM_USER+37          )
#define LS_VIEWERCONTROL_SEND_AS_MAIL  (WM_USER+39          )
#define LS_VIEWERCONTROL_SET_OPTIONSTR (WM_USER+40          ) /* see docs, wParam = (LPCTSTR)key, lParam = (LPCTSTR)value */
#define LS_VIEWERCONTROL_GET_OPTIONSTR (WM_USER+41          ) /* see docs, wParam = (LPCTSTR)key, lParam = (LPCTSTR)value */
#define LS_VIEWERCONTROL_GET_OPTIONSTRLEN (WM_USER+42          ) /* see docs, wParam = (LPCTSTR)key (returns size in TCHARs) */
#define LS_VIEWERCONTROL_SET_NTFYCALLBACK (WM_USER+43          ) /* lParam = LRESULT ( WINAPI fn* )(UINT nMsg, LPARAM lParam, UINT nUserParameter); */
#define LS_VIEWERCONTROL_GET_NTFYCALLBACK (WM_USER+44          ) /* LRESULT ( WINAPI fn* )(UINT nMsg, LPARAM lParam, UINT nUserParameter); */
#define LS_VIEWERCONTROL_GET_TOOLBARBUTTONSTATE (WM_USER+45          ) /* wParam=nID -> -1=hidden, 1=enabled, 2=disabled (only when toobar present, to sync menu state) */
#define LS_VIEWERCONTROL_SET_FOCUS     (WM_USER+46          )
#define LS_VCSF_PREVIEW                (1                   )
#define LS_VCSF_SKETCHLIST             (2                   )
#define LS_VCSF_TOC                    (3                   )
#define LS_VIEWERCONTROL_ADDTOOLBARITEM (WM_USER+47          )
#define LS_VIEWERCONTROL_INTERNAL_CHECKERRORLIST (WM_USER+48          )
#define LS_VIEWERCONTROL_SET_THEATERMODE (WM_USER+49          ) /* 0=non-theater, 1=with frame, 2=without frame */
#define LS_VIEWERCONTROL_SET_THEATERFLIPDELAY (WM_USER+50          ) /* ms for each page */
#define LS_VIEWERCONTROL_SET_THEATERFLIPMODE (WM_USER+51          ) /* wParam = mode */
#define LS_VCTFM_NONE                  (0                   )
#define LS_VCTFM_LINEAR                (1                   ) /* lParam = (LPCTSTR)ProgID */
#define LS_VCTFM_FADE                  (2                   )
#define LS_VCTFM_WHEEL                 (3                   )
#define LS_VIEWERCONTROL_SELECT_THEATERXFORM (WM_USER+52          )
#define LS_VIEWERCONTROL_NTFY_PRVFSCHANGED (WM_USER+53          ) /* wParam = ILLPreviewFileSystemChangeNotifier::enPrvFSChange.. */
#define LS_VIEWERCONTROL_SET_PROGRESSINFO (WM_USER+54          ) /* wParam = nPercentage (-1=finished...), lParam = (LPCTSTR)sText */
#define LS_VIEWERCONTROL_GET_FILENAME  (WM_USER+55          ) /* lParam = LPTSTR pszFilename, wParam = sizeofTSTR(pszBuffer). Returns size needed if NULL filename */
#define LS_VIEWERCONTROL_QUERY_PRVFS_COMPLETE (WM_USER+56          ) /* indicates whether the STGSYS file is complete (1=complete, 2=finished, but incomplete) */
#define LS_VIEWERCONTROL_ONSIZEMOVE    (WM_USER+57          ) /* wParam = 0 (ENTER), 1 (EXIT) */
#define LS_VIEWERCONTROL_NTFY_SHOW     (WM_USER+58          ) /* internal use */
#define LS_VIEWERCONTROL_GET_IDEVICEINFO (WM_USER+59          ) /* internal use */
#define LS_VIEWERCONTROL_REMOVEFAILURETOOLTIPS (WM_USER+60          ) /* internal use */
#define LS_VIEWERCONTROL_SET_LLNTFYSINK (WM_USER+61          ) /* internal use */
#define LS_VIEWERCONTROL_OPEN_PREVSTG  (WM_USER+62          )
#define LS_VIEWERCONTROL_OPEN_NEXTSTG  (WM_USER+63          )
#define LS_VIEWERCONTROL_NTFY_PAGELOADED (1                   ) /* lParam = page# */
#define LS_VIEWERCONTROL_NTFY_UPDATETOOLBAR (2                   ) /* called when control does NOT have an own toolbar. lParam = 1 if count of pages did change */
#define LS_VIEWERCONTROL_NTFY_PRINT_START (3                   ) /* lParam = &scViewerControlPrintData, return 1 to abort print */
#define LS_VIEWERCONTROL_NTFY_PRINT_PAGE (4                   ) /* lParam = &scViewerControlPrintData, return 1 to abort loop */
#define LS_VIEWERCONTROL_NTFY_PRINT_END (5                   ) /* lParam = &scViewerControlPrintData */
#define LS_VIEWERCONTROL_NTFY_TOOLBARUPDATE (6                   ) /* lParam = toolbar handle, called when control has an own toolbar */
#define LS_VIEWERCONTROL_NTFY_EXITBTNPRESSED (7                   )
#define LS_VIEWERCONTROL_NTFY_BTNPRESSED (8                   ) /* lParam = control ID */
#define LS_VIEWERCONTROL_QUEST_BTNSTATE (9                   ) /* lParam = control ID, -1 to hide, 1 to show, 2 to disable (0 to use default) */
#define LS_VIEWERCONTROL_NTFY_ERROR    (10                  ) /* lParam = &scVCError. Return != 0 to suppress error mbox from control. */
#define LS_VIEWERCONTROL_NTFY_MAIL_SENT (11                  ) /* lParam = Stream* of EML mail contents */
#define LS_VIEWERCONTROL_NTFY_DOWNLOADFINISHED (12                  ) /* lParam = 0 (failed), 1 (ok) */
#define LS_VIEWERCONTROL_NTFY_KEYBOARDMESSAGE (13                  ) /* lParam = const MSG*. Return TRUE if message should be taken out of the input queue */
#define LS_VIEWERCONTROL_NTFY_VIEWCHANGED (14                  ) /* lParam = const scViewChangedInfo */
#define LS_VIEWERCONTROL_CMND_SAVEDATA (15                  ) /* return: 0 = OK, -1 = failure, 1 = save in LL file too [event used only if AUTOSAVE is TRUE] */
#define LS_VIEWERCONTROL_NTFY_DATACHANGED (16                  )
#define LS_VIEWERCONTROL_NTFY_PROGRESS (17                  ) /* lParam = percentage (-1=finished). return: 1 if internal progress bar shall be suppressed */
#define LS_VIEWERCONTROL_QUEST_SUPPORTCONTINUATION (18                  ) /* return: 1 if continuation button () should be displayed */
#define LS_VIEWERCONTROL_CMND_CONTINUE (19                  ) /* continue report! */
#define LS_VIEWERCONTROL_NTFY_VIEWERDRILLDOWN (20                  ) /* lParam:  */
#define LS_VIEWERCONTROL_QUEST_DRILLDOWNSUPPORT (21                  ) /* 1 to allow (default), 0 to deny (if provider cannot handle multiple threads or so) */
#define LS_VIEWERCONTROL_OPEN_STORAGE_IN_NEW_WINDOW (22                  ) /* lParam = &scOpenStorageInNewWindow. Reply with 1 if done. */
#define LS_MAILCONFIG_GLOBAL           (0x0001              )
#define LS_MAILCONFIG_USER             (0x0002              )
#define LS_MAILCONFIG_PROVIDER         (0x0004              )
#define LS_DIO_CHECKBOX                (0                   )
#define LS_DIO_PUSHBUTTON              (1                   )
#define LS_GOTFG_FLAG_REORDER          (0x00000001          )
#define LSMAILVIEW_HTMLRIGHT_ALLOW_NONE (0x0000              )
#define LSMAILVIEW_HTMLRIGHT_ALLOW_NEW_WINDOW (0x0001              )
#define LSMAILVIEW_HTMLRIGHT_ALLOW_NAVIGATION (0x0002              )
#define LSMAILVIEW_HTMLRIGHT_ALLOW_JAVA (0x0004              )
#define LSMAILVIEW_HTMLRIGHT_ALLOW_SCRIPTING (0x0008              )
#define LSMAILVIEW_HTMLRIGHT_ALLOW_ACTIVEX (0x0010              )
#define LSMAILVIEW_HTMLRIGHT_ALLOW_ONLINE (0x0020              )
#define LSMAILVIEW_HTMLRIGHT_ALLOW_BROWSERCONTEXTMENU (0x0040              )
#define LSMAILVIEW_HTMLRIGHT_ALLOW_PRINT (0x0080              )

/*--- function declaration ---*/

#if !defined(_RC_INVOKED_) && !defined(RC_INVOKED)

#if defined(_WIN64)
#  pragma pack(push,8)
# else // _WIN64
#  if __WATCOMC__ > 1000 || _MSC_VER >= 1400 /* Watcom C++ >= 10.x or MSC >= 2005 */
#    pragma pack(push,4)
#   elif __BORLANDC__ /* Borland C++ */
#    pragma option -a4
#   else
#    pragma pack(4) /* MS, Watcom <= 10.0, ... */
#  endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

  #define LS_MAKE_NTFY_PRVFSCHANGED_WPARAM(nCmd,nSerialID,nJob,nPage) MAKELONG(nCmd,nSerialID)
  #define LS_MAKE_NTFY_PRVFSCHANGED_LPARAM(nCmd,nSerialID,nJob,nPage) MAKELONG(nPage,nJob)
  #define LS_NTFY_PRVFSCHANGED_CMD(wParam,lParam)      LOWORD(wParam)
  #define LS_NTFY_PRVFSCHANGED_SERIALID(wParam,lParam)     HIWORD(wParam)
  #define LS_NTFY_PRVFSCHANGED_JOB(wParam,lParam)      HIWORD(lParam)
  #define LS_NTFY_PRVFSCHANGED_PAGE(wParam,lParam)      LOWORD(lParam)
 #ifndef IMPLEMENTATION
 
 struct scOpenStorageInNewWindow
   {
   UINT        _nSize;
   LPCWSTR     _pszStgPath;
   BOOL  _bDeleteOnClose;
   };
 
 #endif // IMPLEMENTATION
 #ifndef IMPLEMENTATION
 struct scViewerControlPrintDataA
  {
  UINT  _nSize;
  UINT  _nPages;  // total count of pages
  UINT  _nABCABCCopies; // total count of ABCABC copies
  UINT  _nPage;   // current page (0.._nPages-1)
  UINT  _nCopy;   // current copy (0.._nABCABCCopies-1)
  UINT  _nABCABCCopy;
  LPCSTR  _pszDevice;  // LS_VIEWERCONTROL_NTFY_PRINT_START: "FAX" or "Printer"; LS_VIEWERCONTROL_NTFY_PRINT_PAGE: device name; NULL else
  LPCSTR  _pszProject; // dito
  LPCSTR  _pszJobName; // dito
  UINT  _nAAABBBCCCCopies; // total amount
  };
 struct scViewerControlPrintDataW
  {
  UINT  _nSize;
  UINT  _nPages;  // total count of pages
  UINT  _nABCABCCopies; // total count of ABCABC copies
  UINT  _nPage;   // current page (0.._nPages-1)
  UINT  _nCopy;   // current copy (0.._nABCABCCopies-1)
  UINT  _nABCABCCopy;
  LPCWSTR  _pszDevice;  // LS_VIEWERCONTROL_NTFY_PRINT_START: "FAX" or "Printer"; LS_VIEWERCONTROL_NTFY_PRINT_PAGE: device name; NULL else
  LPCWSTR  _pszProject; // dito
  LPCWSTR  _pszJobName; // dito
  UINT  _nAAABBBCCCCopies; // total amount
  };
 #if defined(UNICODE)
     #define scViewerControlPrintData scViewerControlPrintDataW
   #else
     #define scViewerControlPrintData scViewerControlPrintDataA
 #endif
 
 struct scVCErrorW
  {
  UINT  _nSize;
  UINT  _nErrorCode;
  LPCWSTR  _pszErrortext;
  };
 struct scVCErrorA
  {
  UINT  _nSize;
  UINT  _nErrorCode;
  LPCSTR  _pszErrortext;
  };
 #if defined(UNICODE)
     #define scVCError scVCErrorW
   #else
     #define scVCError scVCErrorA
 #endif
 
 struct scViewChangedInfo
  {
  UINT  _nSize;
  double  _fZoom;
  double  _fOffsetX;
  double  _fOffsetY;
   BOOL  _bPresentationMode;
  };
 #endif // IMPLEMENTATION
 #if !defined(IMPLEMENTATION)
 struct scDIOOptions
  {
  int  _nSize;
  int  _nFlags; // reserved
  };
 #if defined(__cplusplus)
 struct scDIOOptionsCheckbox
  : public scDIOOptions
  {
  int  _nChecked;
  int  _nStyle;
  BOOL _bFocus;
   LPCWSTR _pszText; // NULL for now, reserved...
  };
 struct scDIOOptionsPushbutton
  : public scDIOOptions
  {
  BOOL _bPressed;
  int  _nStyle;
  BOOL _bFocus;
   LPCWSTR _pszText;
   HFONT   _hFont;
  };
 #endif /* __cplusplus */
 #endif /* IMPLEMENTATION */
 interface ILLPreviewFileSystem;
 #ifndef IMPLEMENTATION
 
 struct scStorageOpenInfo
   {
   UINT        _nSize;
   LPCWSTR     _pszTempPath;
   void*       _pApp;
   bool        _bReadOnly;
   bool        _bOneJobTranslation;
   };
 
 #endif // IMPLEMENTATION
 
 


#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysStorageOpen LlStgsysStorageOpenW
       #define LlStgsysStorageOpenO LlStgsysStorageOpenA
     #else  // not UNICODE
       #define LlStgsysStorageOpen LlStgsysStorageOpenA
       #define LlStgsysStorageOpenO LlStgsysStorageOpenW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI HLLSTG   DLLPROC  LlStgsysStorageOpenA
	(
	LPCSTR               lpszFilename,
	LPCSTR               pszTempPath,
	BOOL                 bReadOnly,
	BOOL                 bOneJobTranslation
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI HLLSTG   DLLPROC  LlStgsysStorageOpenW
	(
	LPCWSTR              lpszFilename,
	LPCWSTR              pszTempPath,
	BOOL                 bReadOnly,
	BOOL                 bOneJobTranslation
	);
#endif // WIN32

CMBT_LS_WINAPI void     DLLPROC  LlStgsysStorageClose
	(
	HLLSTG               hStg
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetAPIVersion
	(
	HLLSTG               hStg
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetFileVersion
	(
	HLLSTG               hStg
	);

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysGetFilename LlStgsysGetFilenameW
       #define LlStgsysGetFilenameO LlStgsysGetFilenameA
     #else  // not UNICODE
       #define LlStgsysGetFilename LlStgsysGetFilenameA
       #define LlStgsysGetFilenameO LlStgsysGetFilenameW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetFilenameA
	(
	HLLSTG               hStg,
	INT                  nJob,
	INT                  nFile,
	LPSTR                pszBuffer,
	UINT                 nBufSize
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetFilenameW
	(
	HLLSTG               hStg,
	INT                  nJob,
	INT                  nFile,
	LPWSTR               pszBuffer,
	UINT                 nBufSize
	);
#endif // WIN32

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetJobCount
	(
	HLLSTG               hStg
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysSetJob
	(
	HLLSTG               hStg,
	INT                  nJob
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetJob
	(
	HLLSTG               hStg
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetPageCount
	(
	HLLSTG               hStg
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetJobOptionValue
	(
	HLLSTG               hStg,
	INT                  nOption
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetPageOptionValue
	(
	HLLSTG               hStg,
	INT                  nPageIndex,
	INT                  nOption
	);

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysGetPageOptionString LlStgsysGetPageOptionStringW
       #define LlStgsysGetPageOptionStringO LlStgsysGetPageOptionStringA
     #else  // not UNICODE
       #define LlStgsysGetPageOptionString LlStgsysGetPageOptionStringA
       #define LlStgsysGetPageOptionStringO LlStgsysGetPageOptionStringW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetPageOptionStringA
	(
	HLLSTG               hStg,
	INT                  nPageIndex,
	INT                  nOption,
	LPSTR                pszBuffer,
	UINT                 nBufSize
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetPageOptionStringW
	(
	HLLSTG               hStg,
	INT                  nPageIndex,
	INT                  nOption,
	LPWSTR               pszBuffer,
	UINT                 nBufSize
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysSetPageOptionString LlStgsysSetPageOptionStringW
       #define LlStgsysSetPageOptionStringO LlStgsysSetPageOptionStringA
     #else  // not UNICODE
       #define LlStgsysSetPageOptionString LlStgsysSetPageOptionStringA
       #define LlStgsysSetPageOptionStringO LlStgsysSetPageOptionStringW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysSetPageOptionStringA
	(
	HLLSTG               hStg,
	INT                  nPageIndex,
	INT                  nOption,
	LPCSTR               pszBuffer
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysSetPageOptionStringW
	(
	HLLSTG               hStg,
	INT                  nPageIndex,
	INT                  nOption,
	LPCWSTR              pszBuffer
	);
#endif // WIN32

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysAppend
	(
	HLLSTG               hStg,
	HLLSTG               hStgToAppend
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysDeleteJob
	(
	HLLSTG               hStg,
	INT                  nPageIndex
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysDeletePage
	(
	HLLSTG               hStg,
	INT                  nPageIndex
	);

CMBT_LS_WINAPI HANDLE   DLLPROC  LlStgsysGetPageMetafile
	(
	HLLSTG               hStg,
	INT                  nPageIndex
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysDestroyMetafile
	(
	HANDLE               hMF
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysDrawPage
	(
	HLLSTG               hStg,
	HDC                  hDC,
	HDC                  hPrnDC,
	BOOL                 bAskPrinter,
	_PCRECT              pRC,
	INT                  nPageIndex,
	BOOL                 bFit,
	LPVOID               pReserved
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetLastError
	(
	HLLSTG               hStg
	);

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysDeleteFiles
	(
	HLLSTG               hStg
	);

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysPrint LlStgsysPrintW
       #define LlStgsysPrintO LlStgsysPrintA
     #else  // not UNICODE
       #define LlStgsysPrint LlStgsysPrintA
       #define LlStgsysPrintO LlStgsysPrintW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysPrintA
	(
	HLLSTG               hStg,
	LPCSTR               pszPrinterName1,
	LPCSTR               pszPrinterName2,
	INT                  nStartPageIndex,
	INT                  nEndPageIndex,
	INT                  nCopies,
	UINT                 nFlags,
	LPCSTR               pszMessage,
	HWND                 hWndParent
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysPrintW
	(
	HLLSTG               hStg,
	LPCWSTR              pszPrinterName1,
	LPCWSTR              pszPrinterName2,
	INT                  nStartPageIndex,
	INT                  nEndPageIndex,
	INT                  nCopies,
	UINT                 nFlags,
	LPCWSTR              pszMessage,
	HWND                 hWndParent
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysStoragePrint LlStgsysStoragePrintW
       #define LlStgsysStoragePrintO LlStgsysStoragePrintA
     #else  // not UNICODE
       #define LlStgsysStoragePrint LlStgsysStoragePrintA
       #define LlStgsysStoragePrintO LlStgsysStoragePrintW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysStoragePrintA
	(
	LPCSTR               lpszFilename,
	LPCSTR               pszTempPath,
	LPCSTR               pszPrinterName1,
	LPCSTR               pszPrinterName2,
	INT                  nStartPageIndex,
	INT                  nEndPageIndex,
	INT                  nCopies,
	UINT                 nFlags,
	LPCSTR               pszMessage,
	HWND                 hWndParent
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysStoragePrintW
	(
	LPCWSTR              lpszFilename,
	LPCWSTR              pszTempPath,
	LPCWSTR              pszPrinterName1,
	LPCWSTR              pszPrinterName2,
	INT                  nStartPageIndex,
	INT                  nEndPageIndex,
	INT                  nCopies,
	UINT                 nFlags,
	LPCWSTR              pszMessage,
	HWND                 hWndParent
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysGetPagePrinter LlStgsysGetPagePrinterW
       #define LlStgsysGetPagePrinterO LlStgsysGetPagePrinterA
     #else  // not UNICODE
       #define LlStgsysGetPagePrinter LlStgsysGetPagePrinterA
       #define LlStgsysGetPagePrinterO LlStgsysGetPagePrinterW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetPagePrinterA
	(
	HLLSTG               hStg,
	INT                  nPageIndex,
	LPSTR                pszDeviceName,
	UINT                 nDeviceNameSize,
	PHGLOBAL             phDevMode
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetPagePrinterW
	(
	HLLSTG               hStg,
	INT                  nPageIndex,
	LPWSTR               pszDeviceName,
	UINT                 nDeviceNameSize,
	PHGLOBAL             phDevMode
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI void     DLLPROC  LsSetDebug
	(
	BOOL                 bOn
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsGetViewerControlClassName LsGetViewerControlClassNameW
       #define LsGetViewerControlClassNameO LsGetViewerControlClassNameA
     #else  // not UNICODE
       #define LsGetViewerControlClassName LsGetViewerControlClassNameA
       #define LsGetViewerControlClassNameO LsGetViewerControlClassNameW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI LPCSTR   DLLPROC  LsGetViewerControlClassNameA
	(
	void
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI LPCWSTR  DLLPROC  LsGetViewerControlClassNameW
	(
	void
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI UINT     DLLPROC  LsGetViewerControlDefaultMessage
	(
	void
	);
#endif // WIN32

CMBT_LS_WINAPI INT      DLLPROC  LsCreateViewerControlOverParent
	(
	HSTG                 hStg,
	HWND                 hParentControl
	);

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysGetJobOptionStringEx LlStgsysGetJobOptionStringExW
       #define LlStgsysGetJobOptionStringExO LlStgsysGetJobOptionStringExA
     #else  // not UNICODE
       #define LlStgsysGetJobOptionStringEx LlStgsysGetJobOptionStringExA
       #define LlStgsysGetJobOptionStringExO LlStgsysGetJobOptionStringExW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetJobOptionStringExA
	(
	HLLSTG               hStg,
	LPCSTR               pszKey,
	LPSTR                pszBuffer,
	UINT                 nBufSize
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetJobOptionStringExW
	(
	HLLSTG               hStg,
	LPCWSTR              pszKey,
	LPWSTR               pszBuffer,
	UINT                 nBufSize
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysSetJobOptionStringEx LlStgsysSetJobOptionStringExW
       #define LlStgsysSetJobOptionStringExO LlStgsysSetJobOptionStringExA
     #else  // not UNICODE
       #define LlStgsysSetJobOptionStringEx LlStgsysSetJobOptionStringExA
       #define LlStgsysSetJobOptionStringExO LlStgsysSetJobOptionStringExW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysSetJobOptionStringExA
	(
	HLLSTG               hStg,
	LPCSTR               pszKey,
	LPCSTR               pszBuffer
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysSetJobOptionStringExW
	(
	HLLSTG               hStg,
	LPCWSTR              pszKey,
	LPCWSTR              pszBuffer
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsConversionJobOpen LsConversionJobOpenW
       #define LsConversionJobOpenO LsConversionJobOpenA
     #else  // not UNICODE
       #define LsConversionJobOpen LsConversionJobOpenA
       #define LsConversionJobOpenO LsConversionJobOpenW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI HLSCNVJOB DLLPROC  LsConversionJobOpenA
	(
	HWND                 hWndParent,
	INT                  nLanguage,
	LPCSTR               pszFormat
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI HLSCNVJOB DLLPROC  LsConversionJobOpenW
	(
	HWND                 hWndParent,
	INT                  nLanguage,
	LPCWSTR              pszFormat
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionJobClose
	(
	HLSCNVJOB            hCnvJob
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionConvertEMFToStream
	(
	HLSCNVJOB            hCnvJob,
	HENHMETAFILE         hEMF,
	PSTREAM              pStream
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionConvertStgToStream
	(
	HLSCNVJOB            hCnvJob,
	HLLSTG               hStg,
	PSTREAM              pStream
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsConversionPrint LsConversionPrintW
       #define LsConversionPrintO LsConversionPrintA
     #else  // not UNICODE
       #define LsConversionPrint LsConversionPrintA
       #define LsConversionPrintO LsConversionPrintW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionPrintA
	(
	HLSCNVJOB            hCnvJob,
	PSTREAM              pStream,
	LPSTR                pszBufFilename,
	UINT                 nBufSize
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionPrintW
	(
	HLSCNVJOB            hCnvJob,
	PSTREAM              pStream,
	LPWSTR               pszBufFilename,
	UINT                 nBufSize
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionConfigurationDlg
	(
	HLSCNVJOB            hCnvJob,
	HWND                 hWndParent
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsConversionSetOptionString LsConversionSetOptionStringW
       #define LsConversionSetOptionStringO LsConversionSetOptionStringA
     #else  // not UNICODE
       #define LsConversionSetOptionString LsConversionSetOptionStringA
       #define LsConversionSetOptionStringO LsConversionSetOptionStringW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionSetOptionStringA
	(
	HLSCNVJOB            hCnvJob,
	LPCSTR               pszKey,
	LPCSTR               pszData
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionSetOptionStringW
	(
	HLSCNVJOB            hCnvJob,
	LPCWSTR              pszKey,
	LPCWSTR              pszData
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsConversionGetOptionString LsConversionGetOptionStringW
       #define LsConversionGetOptionStringO LsConversionGetOptionStringA
     #else  // not UNICODE
       #define LsConversionGetOptionString LsConversionGetOptionStringA
       #define LsConversionGetOptionStringO LsConversionGetOptionStringW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionGetOptionStringA
	(
	HLSCNVJOB            hCnvJob,
	LPCSTR               pszKey,
	LPSTR                pszBuffer,
	UINT                 nBufSize
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionGetOptionStringW
	(
	HLSCNVJOB            hCnvJob,
	LPCWSTR              pszKey,
	LPWSTR               pszBuffer,
	UINT                 nBufSize
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsConversionConvertEMFToFile LsConversionConvertEMFToFileW
       #define LsConversionConvertEMFToFileO LsConversionConvertEMFToFileA
     #else  // not UNICODE
       #define LsConversionConvertEMFToFile LsConversionConvertEMFToFileA
       #define LsConversionConvertEMFToFileO LsConversionConvertEMFToFileW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionConvertEMFToFileA
	(
	HLSCNVJOB            hCnvJob,
	HENHMETAFILE         hEMF,
	LPCSTR               pszFilename
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionConvertEMFToFileW
	(
	HLSCNVJOB            hCnvJob,
	HENHMETAFILE         hEMF,
	LPCWSTR              pszFilename
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsConversionConvertStgToFile LsConversionConvertStgToFileW
       #define LsConversionConvertStgToFileO LsConversionConvertStgToFileA
     #else  // not UNICODE
       #define LsConversionConvertStgToFile LsConversionConvertStgToFileA
       #define LsConversionConvertStgToFileO LsConversionConvertStgToFileW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionConvertStgToFileA
	(
	HLSCNVJOB            hCnvJob,
	HLLSTG               hStg,
	LPCSTR               pszFilename
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsConversionConvertStgToFileW
	(
	HLSCNVJOB            hCnvJob,
	HLLSTG               hStg,
	LPCWSTR              pszFilename
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysStorageConvert LlStgsysStorageConvertW
       #define LlStgsysStorageConvertO LlStgsysStorageConvertA
     #else  // not UNICODE
       #define LlStgsysStorageConvert LlStgsysStorageConvertA
       #define LlStgsysStorageConvertO LlStgsysStorageConvertW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysStorageConvertA
	(
	LPCSTR               pszStgFilename,
	LPCSTR               pszDstFilename,
	LPCSTR               pszFormat
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysStorageConvertW
	(
	LPCWSTR              pszStgFilename,
	LPCWSTR              pszDstFilename,
	LPCWSTR              pszFormat
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysConvert LlStgsysConvertW
       #define LlStgsysConvertO LlStgsysConvertA
     #else  // not UNICODE
       #define LlStgsysConvert LlStgsysConvertA
       #define LlStgsysConvertO LlStgsysConvertW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysConvertA
	(
	HLLSTG               hStg,
	LPCSTR               pszDstFilename,
	LPCSTR               pszFormat
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysConvertW
	(
	HLLSTG               hStg,
	LPCWSTR              pszDstFilename,
	LPCWSTR              pszFormat
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsMailConfigurationDialog LsMailConfigurationDialogW
       #define LsMailConfigurationDialogO LsMailConfigurationDialogA
     #else  // not UNICODE
       #define LsMailConfigurationDialog LsMailConfigurationDialogA
       #define LsMailConfigurationDialogO LsMailConfigurationDialogW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsMailConfigurationDialogA
	(
	HWND                 hWndParent,
	LPCSTR               pszSubkey,
	UINT                 nFlags,
	INT                  nLanguage
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsMailConfigurationDialogW
	(
	HWND                 hWndParent,
	LPCWSTR              pszSubkey,
	UINT                 nFlags,
	INT                  nLanguage
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI HLSMAILJOB DLLPROC  LsMailJobOpen
	(
	INT                  nLanguage
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsMailJobClose
	(
	HLSMAILJOB           hJob
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsMailSetOptionString LsMailSetOptionStringW
       #define LsMailSetOptionStringO LsMailSetOptionStringA
     #else  // not UNICODE
       #define LsMailSetOptionString LsMailSetOptionStringA
       #define LsMailSetOptionStringO LsMailSetOptionStringW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsMailSetOptionStringA
	(
	HLSMAILJOB           hJob,
	LPCSTR               pszKey,
	LPCSTR               pszValue
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsMailSetOptionStringW
	(
	HLSMAILJOB           hJob,
	LPCWSTR              pszKey,
	LPCWSTR              pszValue
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsMailGetOptionString LsMailGetOptionStringW
       #define LsMailGetOptionStringO LsMailGetOptionStringA
     #else  // not UNICODE
       #define LsMailGetOptionString LsMailGetOptionStringA
       #define LsMailGetOptionStringO LsMailGetOptionStringW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsMailGetOptionStringA
	(
	HLSMAILJOB           hJob,
	LPCSTR               pszKey,
	LPSTR                pszBuffer,
	UINT                 nBufSize
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsMailGetOptionStringW
	(
	HLSMAILJOB           hJob,
	LPCWSTR              pszKey,
	LPWSTR               pszBuffer,
	UINT                 nBufSize
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsMailSendFile
	(
	HLSMAILJOB           hJob,
	HWND                 hWndParent
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI void     DLLPROC  LsDrawInputObject
	(
	HWND                 hWnd,
	HDC                  hDC,
	_PRECT               pRC,
	INT                  nType,
	PCSCDIOOPTIONS       pOptions
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LlStgsysGetLLFilename
	(
	LPCTSTR              pszFilename,
	LPCTSTR              pszTempPath,
	LPTSTR               pszBuffer,
	UINT                 nSize
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysStorageCreate LlStgsysStorageCreateW
       #define LlStgsysStorageCreateO LlStgsysStorageCreateA
     #else  // not UNICODE
       #define LlStgsysStorageCreate LlStgsysStorageCreateA
       #define LlStgsysStorageCreateO LlStgsysStorageCreateW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI HLLSTG   DLLPROC  LlStgsysStorageCreateA
	(
	LPCSTR               lpszFilename,
	LPCSTR               pszTempPath,
	HDC                  hRefDC,
	_PCRECT              prcArea,
	BOOL                 bPhysicalPage
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI HLLSTG   DLLPROC  LlStgsysStorageCreateW
	(
	LPCWSTR              lpszFilename,
	LPCWSTR              pszTempPath,
	HDC                  hRefDC,
	_PCRECT              prcArea,
	BOOL                 bPhysicalPage
	);
#endif // WIN32

CMBT_LS_WINAPI INT      DLLPROC  LlStgsysAppendEMF
	(
	HLLSTG               hStg,
	HENHMETAFILE         hEMFToAppend,
	HDC                  hRefDC,
	_PCRECT              prcArea,
	BOOL                 bPhysicalPage
	);

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsProfileStart LsProfileStartW
       #define LsProfileStartO LsProfileStartA
     #else  // not UNICODE
       #define LsProfileStart LsProfileStartA
       #define LsProfileStartO LsProfileStartW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsProfileStartA
	(
	HANDLE               hThread,
	LPCSTR               pszDescr,
	LPCSTR               pszFilename,
	INT                  nTicksMS
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsProfileStartW
	(
	HANDLE               hThread,
	LPCWSTR              pszDescr,
	LPCWSTR              pszFilename,
	INT                  nTicksMS
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI void     DLLPROC  LsProfileEnd
	(
	HANDLE               hThread
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsGetOrgTextFromGlyphsW
	(
	HDC                  hDC,
	_LPCWORD             pszGlyphs,
	INT                  nGlyphs,
	LPWSTR               pszOrgTextBuffer,
	UINT                 nFlags
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LsMailView LsMailViewW
       #define LsMailViewO LsMailViewA
     #else  // not UNICODE
       #define LsMailView LsMailViewA
       #define LsMailViewO LsMailViewW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsMailViewA
	(
	HWND                 hWndParent,
	LPCSTR               pszMailFile,
	UINT                 nRights,
	INT                  nLanguage
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsMailViewW
	(
	HWND                 hWndParent,
	LPCWSTR              pszMailFile,
	UINT                 nRights,
	INT                  nLanguage
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI INT      DLLPROC  LsGetDDXForms
	(
	_PPIEnumString       ppEnumString
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI HLLSTG   DLLPROC  LlStgsysStorageOpen13
	(
	_PILLPreviewFileSystem                     pFileSys
	);
#endif // WIN32

CMBT_LS_WINAPI INT      DLLPROC  LsInternalCreateViewerControlOverParent13
	(
	HWND                 hParentControl,
	UINT                 nFlags
	);

CMBT_LS_WINAPI HWND     DLLPROC  LsInternalGetViewerControlFromParent13
	(
	HWND                 hParentControl
	);

CMBT_LS_WINAPI void     DLLPROC  LsSetDlgboxMode
	(
	UINT                 nMode
	);

CMBT_LS_WINAPI UINT     DLLPROC  LsGetDlgboxMode
	(
	void
	);

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
   #ifdef UNICODE
       #define LlStgsysStorageOpenEx LlStgsysStorageOpenExW
       #define LlStgsysStorageOpenExO LlStgsysStorageOpenExA
     #else  // not UNICODE
       #define LlStgsysStorageOpenEx LlStgsysStorageOpenExA
       #define LlStgsysStorageOpenExO LlStgsysStorageOpenExW
   #endif // UNICODE
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI HLLSTG   DLLPROC  LlStgsysStorageOpenExA
	(
	LPCSTR               lpszFilename,
	PSCSTORAGEOPENINFO   pSOI
	);
#endif // WIN32

#if defined(WIN32) && !defined(_NO_CMLS15APIDEFINES)
#endif // WIN32, _NO_CMLS15APIDEFINES
#ifdef WIN32
CMBT_LS_WINAPI HLLSTG   DLLPROC  LlStgsysStorageOpenExW
	(
	LPCWSTR              lpszFilename,
	PSCSTORAGEOPENINFO   pSOI
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI LPCWSTR  DLLPROC  LsGetViewerControlClassNameEx
	(
	void
	);
#endif // WIN32

#ifdef WIN32
CMBT_LS_WINAPI BOOL     DLLPROC  LsGetDebug
	(
	void
	);
#endif // WIN32



#ifdef __cplusplus
}
#endif

#if __WATCOMC__ > 1000 || _MSC_VER >= 1400 /* Watcom C++ >= 10.x or MSC >= 2005 */
#pragma pack(pop)
#elif __BORLANDC__ /* Borland C++ */
#pragma option -a.
#else
#pragma pack() /* others */
#endif

#endif  /* #ifndef _RC_INVOKED_ */

#endif  /* #ifndef _LS15_H */

