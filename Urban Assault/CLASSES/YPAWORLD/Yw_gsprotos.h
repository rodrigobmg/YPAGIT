/*** Alle Prototypen zur Shell ***/

void yw_HandleGameShell( struct ypaworld_data *ywd, struct GameShellReq *GSR );
void yw_LayoutGameShell( struct ypaworld_data *ywd, struct GameShellReq *GSR );
void yw_FreeGameShell( struct ypaworld_data *ywd, struct GameShellReq *GSR );
void yw_DrawInputMenu(struct ypaworld_data *ywd, struct GameShellReq *GSR);
void yw_DrawVideoMenu(struct ypaworld_data *ywd, struct GameShellReq *GSR);
void yw_DrawDiskMenu(struct ypaworld_data *ywd, struct GameShellReq *GSR);
#ifdef __NETWORK__
void yw_DrawNetMenu(struct ypaworld_data *ywd, struct GameShellReq *GSR);
#endif
void yw_DrawLocaleMenu(struct ypaworld_data *ywd, struct GameShellReq *GSR);
void yw_InitKeyTable( struct ypaworld_data *ywd );
void yw_MakeActiveReq( struct GameShellReq *GSR, WORD Req );
void yw_PosSelected( struct YPAListReq *req, WORD actual );
void yw_GSMessage( struct GameShellReq *GSR, char *message );
BOOL yw_WasKeyJustUsed( struct GameShellReq *GSR, WORD keycode, WORD modus );
void yw_ActualizeInputRequester( struct GameShellReq *GSR );
void yw_InitVideoList( struct GameShellReq *GSR );
void yw_ScanUserDirectory( struct GameShellReq *GSR, char *dirname, Object *World );
void yw_ScanLocaleDirectory( struct GameShellReq *GSR, char *dirname, Object *World );
BOOL yw_ParseInitData( struct GameShellReq *GSR, UBYTE *filename, UWORD mask,
                       Object *World );
ULONG yw_ParseUserData( struct ScriptParser *parser );
ULONG yw_ParseInputData( struct ScriptParser *parser );
ULONG yw_ParseVideoData( struct ScriptParser *parser );
ULONG yw_ParseSoundData( struct ScriptParser *parser );
ULONG yw_ParseShellData( struct ScriptParser *parser );
ULONG yw_ParseScoreData( struct ScriptParser *parser );
ULONG yw_ParseOwnerMap( struct ScriptParser *parser );
ULONG yw_ParseBuildingMap( struct ScriptParser *parser );
ULONG yw_ParseEnergyMap( struct ScriptParser *parser );
LONG  yw_GetKeycode( char *str );
LONG  yw_GetInternalNumber( ULONG type, ULONG number );
BOOL  yw_WriteUserData( FILE *ifile, char *name, struct GameShellReq *GSR );
BOOL  yw_WriteInputData( FILE *ifile, struct GameShellReq *GSR );
BOOL  yw_WriteVideoData( FILE *ifile, struct GameShellReq *GSR );
BOOL  yw_WriteSoundData( FILE *ifile, struct GameShellReq *GSR );
BOOL  yw_WriteShellData( FILE *ifile, struct GameShellReq *GSR );
BOOL  yw_WriteScoreData( FILE *ifile, struct GameShellReq *GSR );
void  yw_SetAllKeys( Object * world, struct GameShellReq *GSR );

UBYTE *yw_MenuLayoutSelItem(struct ypaworld_data *, struct YPAListReq *, UBYTE *, UBYTE *, UBYTE);
void  yw_SetFarView( Object *world, BOOL really );
void  yw_GameShellToolTips( struct GameShellReq *GSR, ULONG who );
ULONG yw_ParseShellSounds( struct ScriptParser *parser );
ULONG yw_ParseShellTracks( struct ScriptParser *parser );
BOOL  yw_ParseShellScript( struct GameShellReq *GSR );
void  yw_PlayShellSamples( struct GameShellReq *GSR );

BOOL  yw_SaveGame( FILE *F, struct ypaworld_data *ywd );
BOOL  yw_SaveLevelStatus(  FILE *F, struct ypaworld_data *ywd, ULONG num );
BOOL  yw_SaveAllLevelStatus(  FILE *F, struct ypaworld_data *ywd );
BOOL  yw_SaveAllBuddies(  FILE *F, struct ypaworld_data *ywd );
BOOL  yw_SaveBuddy(  FILE *F, struct ypaworld_data *ywd, ULONG num  );

BOOL  yw_LoadGame(  FILE *F, struct ypaworld_data *ywd );
ULONG yw_ParseLevelStatus(  struct ScriptParser *p );
ULONG yw_ParseBuddy(  struct ScriptParser *p );
void  yw_DrawUserName( struct GameShellReq *GSR );
LONG  yw_HowMuchNodes( struct List *l);

BOOL  yw_SaveWorld( struct ypaworld_data *ywd, FILE *F );
BOOL  yw_SaveVehicles( struct ypaworld_data *ywd, FILE *F );
BOOL  yw_SaveRobo( struct OBNode  *o, FILE *F );
BOOL  yw_SaveCommander( struct OBNode  *o, FILE *F );
BOOL  yw_SaveSlave( struct OBNode  *o, FILE *F );
BOOL  yw_SaveBacterium( struct OBNode  *o, FILE *F );
BOOL  yw_SaveSpecials( struct OBNode  *o, FILE *F );
BOOL  yw_SaveWunderInfo( struct ypaworld_data  *o, FILE *F );
BOOL  yw_SaveKWFactor( struct ypaworld_data  *o, FILE *F );
BOOL  yw_SaveGlobals( struct ypaworld_data  *o, FILE *F );
BOOL  yw_SaveExtraViewerInfo( struct OBNode  *o, FILE *F );
BOOL  yw_SaveLevelNum( struct ypaworld_data *o, FILE *F );
BOOL  yw_SaveMasks( struct ypaworld_data *o, FILE *F );
BOOL  yw_SaveSuperBombs( struct ypaworld_data *o, FILE *F );
ULONG yw_ParseRobo( struct ScriptParser *parser );
ULONG yw_ParseSlave( struct ScriptParser *parser );
ULONG yw_ParseCommander( struct ScriptParser *parser );
ULONG yw_ParseWunderInfo( struct ScriptParser *parser );
ULONG yw_ParseKWFactor( struct ScriptParser *parser );
ULONG yw_ParseGlobals( struct ScriptParser *parser );
ULONG yw_ParseExtraViewerInfo( struct ScriptParser *parser );
ULONG yw_ParseLevelNum( struct ScriptParser *parser );
ULONG yw_ParseMasks( struct ScriptParser *parser );
ULONG yw_ParseSuperBombs( struct ScriptParser *parser );
BOOL  yw_ExtractVehicleValues( struct ScriptParser *parser );
BOOL  yw_ExtractRoboValues( struct ScriptParser *parser );
ULONG yw_ParseVehicles( struct ypaworld_data *ywd, char *filename );
void  yw_ReorganiseVehicles( struct ypaworld_data *ywd );
void  yw_KillThemAll( struct ypaworld_data *ywd );
void  yw_KillVehicle( struct ypaworld_data *ywd, struct OBNode *vehicle );
struct Bacterium *yw_GetBactFromIdent( ULONG ident, struct ypaworld_data *ywd );
void  yw_RefreshVehicle( struct ypaworld_data *ywd, struct OBNode *vehicle,
                         struct OBNode *robo, BOOL   is_robo );
void  yw_ReorganizeVehicles( struct ypaworld_data *ywd );
BOOL  yw_SaveBuildInfo( struct ypaworld_data *ywd, FILE *SGF );
BOOL  yw_SaveActualEnergyMap( struct ypaworld_data *ywd, FILE *SGF );
BOOL  yw_SaveActualOwnerMap( struct ypaworld_data *ywd, FILE *SGF );
BOOL  yw_SaveActualBuildingMap( struct ypaworld_data *ywd, FILE *SGF );
void  yw_SetPalFX( struct GameShellReq *GSR );
void  yw_SetDestFX( struct GameShellReq *GSR );
void  yw_ClearBuddyArray( struct ypaworld_data *ywd );
BOOL  yw_ExistSaveGame( ULONG Level, char *User );
BOOL  yw_ExistFinalSaveGame( ULONG Level, char *User );
BOOL  yw_ExistRestartSaveGame( ULONG Level, char *User );
BOOL  yw_ExistFileName( char *name );
LONG  yw_InitShellSounds( struct GameShellReq *GSR, struct ScriptParser *parser);
LONG  yw_InitShellVolumes( struct GameShellReq *GSR, struct ScriptParser *parser);
LONG  yw_InitShellPitches( struct GameShellReq *GSR, struct ScriptParser *parser);
void  yw_StrUpper( char *ziel, char *quelle );
void  yw_StrUpper2( char *ziel, char *quelle );
void  yw_NoticeKeys( struct GameShellReq *GSR );
void  yw_NoticeStandardKeys( struct GameShellReq *GSR );
void  yw_RestoreKeys( struct GameShellReq *GSR );
void  yw_RestoreStandardKeys( struct GameShellReq *GSR );
char *yw_AddEmptyLinesToMenu( struct ypaworld_data *ywd, struct YPAListReq *Menu,
                              char *str, int number );
BOOL  yw_WasInputEvent( struct VFMInput *input );
void  yw_CloseNetRequester( struct GameShellReq *GSR );
BOOL  yw_ParseLevelNumber2( char *filename, ULONG *lnum );
UBYTE yw_GetFirstFreeRace( struct GameShellReq *GSR );
void  yw_DoRaceInit( struct GameShellReq *GSR );
void  yw_EAR_Kill( struct GameShellReq *GSR );
void  yw_EAR_Create( struct GameShellReq *GSR );
void  yw_EAR_Load( struct GameShellReq *GSR );
void  yw_EAR_Save( struct GameShellReq *GSR );
void  yw_CopyFile( char *von, char *nach );
void  yw_KillAllFilesInDir( char *fn );
BOOL  yw_IsOKForFilename( char ascii );
void  yw_CancelSettings( struct GameShellReq *GSR );
void  yw_CancelLocale( struct GameShellReq *GSR );
void  yw_CancelNetwork( struct GameShellReq *GSR );
void  yw_CancelDisk( struct GameShellReq *GSR );
void  yw_CancelInput( struct GameShellReq *GSR );
void  yw_OKSettings( struct GameShellReq *GSR );
void  yw_OKLocale( struct GameShellReq *GSR );
void  yw_OKNetwork( struct GameShellReq *GSR );
void  yw_OKDisk( struct GameShellReq *GSR );
void  yw_OKProvider( struct GameShellReq *GSR );
void  yw_OKLevel( struct GameShellReq *GSR );
void  yw_OKSessions( struct GameShellReq *GSR );
void  yw_OpenInput( struct GameShellReq *GSR );
void  yw_OpenAbout( struct GameShellReq *GSR );
void  yw_OpenLocale( struct GameShellReq *GSR );
void  yw_OpenSettings( struct GameShellReq *GSR );
void  yw_OpenDisk( struct GameShellReq *GSR );
void  yw_OpenNetwork( struct GameShellReq *GSR );
void  yw_AppearVideoMode( struct GameShellReq *GSR, BOOL remotestart );
void  yw_BackToTitle( struct GameShellReq *GSR );
void  yw_SortNetworkLevels( struct GameShellReq *GSR );
void  yw_Appear3DDevice( struct GameShellReq *GSR, BOOL remotestart );
void yw_DrawD3DMenu(struct ypaworld_data *ywd, struct GameShellReq *GSR);
void yw_MessageBox( struct ypaworld_data *ywd, char *title, char *text );
void yw_OpenConfirmRequester( struct GameShellReq *GSR, ULONG modus, char *text, ULONG type );
void yw_CloseConfirmRequester( struct GameShellReq *GSR );
void yw_RenderConfirmRequester( struct GameShellReq *GSR );
BOOL  yw_CheckOlderSaveGame( struct GameShellReq *GSR );
void yw_PaintRect( struct GameShellReq *GSR, WORD x, WORD y, WORD w, WORD h );
void yw_StartNetGame( struct GameShellReq *GSR );

