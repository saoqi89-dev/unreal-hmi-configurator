// ProductConfigurator.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProductConfigurator.generated.h"

UCLASS()
class HMICONFIGURATOR_API AProductConfigurator : public AActor
{
    GENERATED_BODY()
    
public:    
    AProductConfigurator();

protected:
    virtual void BeginPlay() override;

public:    
    virtual void Tick(float DeltaTime) override;

    // 产品模型
    UPROPERTY(EditAnywhere, Category = "Config")
    UStaticMeshComponent* ProductMesh;

    // 材质数组
    UPROPERTY(EditAnywhere, Category = "Config")
    TArray<UMaterialInterface*> Materials;

    // 旋转速度
    UPROPERTY(EditAnywhere, Category = "Config")
    float RotateSpeed = 50.0f;

    // 当前材质索引
    int32 CurrentMaterialIndex = 0;

    // 切换到下一材质
    UFUNCTION(BlueprintCallable, Category = "Config")
    void NextMaterial();

    // 切换到上一材质
    UFUNCTION(BlueprintCallable, Category = "Config")
    void PreviousMaterial();

    // 设置指定材质
    UFUNCTION(BlueprintCallable, Category = "Config")
    void SetMaterial(int32 Index);

    // 重置视角
    UFUNCTION(BlueprintCallable, Category = "Config")
    void ResetView();

    // 获取当前配置
    UFUNCTION(BlueprintCallable, Category = "Config")
    FString GetCurrentConfig();

private:
    void ApplyMaterial(int32 Index);
    bool bIsDragging = false;
    FVector2D LastMousePosition;
};
