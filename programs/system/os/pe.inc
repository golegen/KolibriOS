struct STRIPPED_PE_HEADER
  Signature             dw ?
  Characteristics       dw ?
  AddressOfEntryPoint   dd ?
  ImageBase             dd ?
  SectionAlignmentLog   db ?
  FileAlignmentLog      db ?
  MajorOSVersion        db ?
  MinorOSVersion        db ?
  SizeOfImage           dd ?
  SizeOfStackReserve    dd ?
  SizeOfHeapReserve     dd ?
  SizeOfHeaders         dd ?
  Subsystem             db ?
  NumberOfRvaAndSizes   db ?
  NumberOfSections      dw ?
ends
STRIPPED_PE_SIGNATURE = 0x4503 ; 'PE' xor 'S'
SPE_DIRECTORY_IMPORT    = 0
SPE_DIRECTORY_EXPORT    = 1
SPE_DIRECTORY_BASERELOC = 2

struct IMAGE_DATA_DIRECTORY
  VirtualAddress dd  ?
  isize          dd  ?
ends

struct IMAGE_OPTIONAL_HEADER32
  Magic                         dw  ?
  MajorLinkerVersion            db  ?
  MinorLinkerVersion            db  ?
  SizeOfCode                    dd  ?
  SizeOfInitializedData         dd  ?
  SizeOfUninitializedData       dd  ?
  AddressOfEntryPoint           dd  ?
  BaseOfCode                    dd  ?
  BaseOfData                    dd  ?
  ImageBase                     dd  ?
  SectionAlignment              dd  ?
  FileAlignment                 dd  ?
  MajorOperatingSystemVersion   dw  ?
  MinorOperatingSystemVersion   dw  ?
  MajorImageVersion             dw  ?
  MinorImageVersion             dw  ?
  MajorSubsystemVersion         dw  ?
  MinorSubsystemVersion         dw  ?
  Win32VersionValue             dd  ?
  SizeOfImage                   dd  ?
  SizeOfHeaders                 dd  ?
  CheckSum                      dd  ?
  Subsystem                     dw  ?
  DllCharacteristics            dw  ?
  SizeOfStackReserve            dd  ?
  SizeOfStackCommit             dd  ?
  SizeOfHeapReserve             dd  ?
  SizeOfHeapCommit              dd  ?
  LoaderFlags                   dd  ?
  NumberOfDirectories           dd  ?
  DataDirectory                 IMAGE_DATA_DIRECTORY ?
  Directories                   rb  sizeof.IMAGE_DATA_DIRECTORY*15
ends

struct IMAGE_FILE_HEADER
  Machine               dw ?
  NumberOfSections      dw ?
  TimeDateStamp         dd ?
  PointerToSymbolTable  dd ?
  NumberOfSymbols       dd ?
  SizeOfOptionalHeader  dw ?
  Characteristics       dw ?
ends

struct IMAGE_NT_HEADERS
  Signature         dd ?
  FileHeader        IMAGE_FILE_HEADER
  OptionalHeader    IMAGE_OPTIONAL_HEADER32
ends

struct IMAGE_EXPORT_DIRECTORY
  Characteristics       dd  ?
  TimeDateStamp         dd  ?
  MajorVersion          dw  ?
  MinorVersion          dw  ?
  Name                  dd  ?
  Base                  dd  ?
  NumberOfFunctions     dd  ?
  NumberOfNames         dd  ?
  AddressOfFunctions    dd  ?
  AddressOfNames        dd  ?
  AddressOfNameOrdinals dd  ?
ends

struct IMAGE_IMPORT_DIRECTORY
  OriginalFirstThunk    dd ?
  TimeDateStamp         dd ?
  ForwarderChain        dd ?
  Name                  dd ?
  FirstThunk            dd ?
ends

struct IMAGE_DOS_HEADER
  e_magic               dw ?
  e_cblp                dw ?
  e_cp                  dw ?
  e_crlc                dw ?
  e_cparhdr             dw ?
  e_minalloc            dw ?
  e_maxalloc            dw ?
  e_ss                  dw ?
  e_sp                  dw ?
  e_csum                dw ?
  e_ip                  dw ?
  e_cs                  dw ?
  e_lfarlc              dw ?
  e_ovno                dw ?
  e_res                 rw 4
  e_oemid               dw ?
  e_oeminfo             dw ?
  e_res2                rw 10
  e_lfanew              dd ?
ends

struct IMAGE_SECTION_HEADER
  Name                  rb 8
  VirtualSize           dd ?
  VirtualAddress        dd ?
  SizeOfRawData         dd ?
  OffsetToRawData       dd ?
  OffsetToRelocations   dd ?
  OffsetToLinenumbers   dd ?
  NumberOfRelocations   dw ?
  NumberOfLinenumbers   dw ?
  Characteristics       dd ?
ends
