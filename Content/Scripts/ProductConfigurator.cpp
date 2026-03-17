// ProductConfigurator.cpp
#include "ProductConfigurator.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

AProductConfigurator::AProductConfigurator()
{
    PrimaryActorTick.bCanEverTick = true;

    ProductMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ProductMesh"));
    RootComponent = ProductMesh;
}

void AProductConfigurator::BeginPlay()
{
    Super::BeginPlay();
    
    if (Materials.Num() > 0)
    {
        ApplyMaterial(0);
    }
}

void AProductConfigurator::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    
    // 处理输入和旋转逻辑
}

void AProductConfigurator::NextMaterial()
{
    if (Materials.Num() == 0) return;
    
    CurrentMaterialIndex = (CurrentMaterialIndex + 1) % Materials.Num();
    ApplyMaterial(CurrentMaterialIndex);
}

void AProductConfigurator::PreviousMaterial()
{
    if (Materials.Num() == 0) return;
    
    CurrentMaterialIndex = (CurrentMaterialIndex - 1 + Materials.Num()) % Materials.Num();
    ApplyMaterial(CurrentMaterialIndex);
}

void AProductConfigurator::SetMaterial(int32 Index)
{
    if (Index >= 0 && Index < Materials.Num())
    {
        CurrentMaterialIndex = Index;
        ApplyMaterial(Index);
    }
}

void AProductConfigurator::ResetView()
{
    SetActorRotation(FRotator::ZeroRotator);
}

FString AProductConfigurator::GetCurrentConfig()
{
    return FString::Printf(TEXT("Material Index: %d"), CurrentMaterialIndex);
}

void AProductConfigurator::ApplyMaterial(int32 Index)
{
    if (ProductMesh && Materials.IsValidIndex(Index))
    {
        ProductMesh->SetMaterial(0, Materials[Index]);
    }
}
