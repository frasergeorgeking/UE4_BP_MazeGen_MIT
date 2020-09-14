// MIT License Copyright (c) 2020 Fraser King

#include "AssetPicker.h"
#include "AssetRegistryModule.h"
#include "ContentBrowserDelegates.h"
#include "ContentBrowserModule.h"
#include "IContentBrowserSingleton.h"

TSharedRef<SWidget> UAssetPicker::RebuildWidget()
{
    FOnAssetDoubleClicked OnAssetDoubleClicked;
    OnAssetDoubleClicked.BindUFunction(this, FName("OnAssetDoubleClicked")); //Bind OnAssetDoubleClicked Delegate to Custom Function

    // Declare and Initialise Required References
    FAssetRegistryModule& AssetRegistryModuleRef = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
    FContentBrowserModule& ContentBrowserModuleRef = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");
    FARFilter ARFilter;
    FAssetPickerConfig AssetPickerConfig;
    AssetPickerConfig.OnAssetDoubleClicked = OnAssetDoubleClicked;

    //Pull Config Settings from Exposed Editor Variables - Asset Registry Filter
    ARFilter.bIncludeOnlyOnDiskAssets = bIncludeOnlyOnDiskAssets;
    ARFilter.ClassNames = ClassNames;
    ARFilter.ObjectPaths = ObjectPaths;
    ARFilter.PackageNames = PackageNames;
    ARFilter.PackagePaths = PackagePaths;

    //Pull Config Settings from Exposed Editor Variables - Asset Picker Config
    AssetPickerConfig.Filter = ARFilter;
    switch (AssetViewType) //Set Initial Asset View Type
    {
        case Column:
            AssetPickerConfig.InitialAssetViewType = EAssetViewType::Column;
            break;

        case List:
            AssetPickerConfig.InitialAssetViewType = EAssetViewType::List;
            break;
        
        case Tile:
            AssetPickerConfig.InitialAssetViewType = EAssetViewType::Tile;
            break;

        default:
            break;
    }
    AssetPickerConfig.bAddFilterUI = bAddFilterUI;
    AssetPickerConfig.bAllowDragging = bAllowDragging;
    AssetPickerConfig.bAllowNullSelection = bAllowNullSelection;
    AssetPickerConfig.bAutohideSearchBar = bAutohideSearchBar;
    AssetPickerConfig.bCanShowClasses = bCanShowClasses;
    AssetPickerConfig.bCanShowDevelopersFolder = bCanShowDevelopersFolder;
    AssetPickerConfig.bCanShowFolders = bCanShowFolders;
    AssetPickerConfig.bCanShowRealTimeThumbnails = bCanShowRealTimeThumbnails;
    AssetPickerConfig.bFocusSearchBoxWhenOpened = bFocusSearchBoxWhenOpened;
    AssetPickerConfig.bForceShowEngineContent = bForceShowEngineContent;
    AssetPickerConfig.bPreloadAssetsForContextMenu = bPreloadAssetsForContextMenu;
    AssetPickerConfig.bShowBottomToolbar = bShowBottomToolbar;
    AssetPickerConfig.bShowPathInColumnView = bShowPathInColumnView;
    AssetPickerConfig.bShowTypeInColumnView = bShowTypeInColumnView;
    AssetPickerConfig.bSortByPathInColumnView = bSortByPathInColumnView;

    return ContentBrowserModuleRef.Get().CreateAssetPicker(AssetPickerConfig);
    
}

void UAssetPicker::OnAssetDoubleClicked(const FAssetData& AssetData)
{
    OnAssetDoubleClickedEvent.Broadcast(AssetData); // Execute BP Event
}