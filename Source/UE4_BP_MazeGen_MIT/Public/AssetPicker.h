// MIT License Copyright (c) 2020 Fraser King

#pragma once

#include "CoreMinimal.h"
#include "IContentBrowserSingleton.h"
#include "Components/Widget.h"
#include "AssetPicker.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAssetDoubleClickedEvent, const FAssetData&, AssetData); // Declare BP Compatible Delegate for Double Click (Must be Dynamic Multicast)

UENUM(BlueprintType)
enum EAssetViewTypeBP
{
	Column,
	List,
	Tile
};

// This class acts as a UMG wrapper for the slate class SAssetPicker (SAssetPicker constructed via Content Browser Singleton)

UCLASS()
class UE4_BP_MAZEGEN_MIT_API UAssetPicker : public UWidget
{
	GENERATED_BODY()

	public:
	// Variables
	UPROPERTY(BlueprintAssignable, Category="Event")
	FOnAssetDoubleClickedEvent OnAssetDoubleClickedEvent; // Exposes Double Clicked Delegate as BP Event

	// Asset Registry Filter Options
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Registry Filter")
	bool bIncludeOnlyOnDiskAssets = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Registry Filter")
	TArray<FName> ClassNames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Registry Filter")
	TArray<FName> ObjectPaths;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Registry Filter")
	TArray<FName> PackageNames;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Registry Filter")
	TArray<FName> PackagePaths;

	// Asset Picker Config Options
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	TEnumAsByte<EAssetViewTypeBP> AssetViewType = Tile;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bAddFilterUI = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bAllowDragging = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bAllowNullSelection = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bAutohideSearchBar = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bCanShowClasses = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bCanShowDevelopersFolder = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bCanShowFolders = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bCanShowRealTimeThumbnails = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bFocusSearchBoxWhenOpened = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bForceShowEngineContent = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bPreloadAssetsForContextMenu = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bShowBottomToolbar = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bShowPathInColumnView = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bShowTypeInColumnView = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Asset Picker Configuration")
	bool bSortByPathInColumnView = false;

	// Functions
	UFUNCTION()
	void OnAssetDoubleClicked(const FAssetData& AssetData);
	
	protected:
	// Start of Slate Interface
	virtual TSharedRef<SWidget> RebuildWidget() override;
#if WITH_EDITOR
	virtual TSharedRef<SWidget> RebuildDesignWidget(TSharedRef<SWidget> Content) override { return Content; }
#endif
	// End of Slate Interface
};
