# Unreal Engine 3D HMI 配置器

基于 Unreal Engine 5 的3D产品配置器Demo。

## 功能特性

- 3D模型展示
- 材质/颜色切换
- 360度旋转查看
- 鼠标/触摸交互
- 产品配置预览

## 技术栈

- Unreal Engine 5.3+
- C++ / Blueprints
- UMG UI

## 项目结构

```
Content/
├── Scripts/          # C++代码
├── Materials/       # 材质
├── Blueprints/      # 蓝图
├── Levels/          # 关卡
└── StaticMeshes/    # 静态网格体
```

## 快速开始

1. 安装 Unreal Engine 5.3+
2. 克隆项目
3. 用 Unreal Editor 打开 `.uproject` 文件
4. 运行

## 核心模块

### BP_ProductConfigurator
产品配置器蓝图，负责材质切换和交互。

### BP_CameraController
相机控制蓝图，实现轨道旋转。

### W_ConfigPanel
配置面板UI。

---

*创建时间: 2026-03-17*
