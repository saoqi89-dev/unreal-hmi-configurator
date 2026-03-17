# Unreal Engine 3D HMI 配置器 - 架构文档

## 1. 项目概述

**项目名称**: unreal-hmi-configurator  
**项目类型**: 3D产品配置器Demo  
**核心功能**: 3D模型展示、材质切换、360度旋转、配置预览

---

## 2. 技术架构

- **引擎**: Unreal Engine 5.3+
- **语言**: C++ / Blueprints
- **UI系统**: UMG
- **渲染**: Nanite / Lumen

---

## 3. 核心模块

### ProductConfigurator (C++)
| 方法 | 说明 |
|------|------|
| NextMaterial() | 切换下一材质 |
| PreviousMaterial() | 切换上一材质 |
| SetMaterial(Index) | 设置指定材质 |
| ResetView() | 重置视角 |

### BP_ProductConfigurator (Blueprint)
蓝图版本，方便快速迭代。

### BP_CameraController
轨道相机控制。

---

## 4. 交互方式

- 鼠标拖动旋转
- 滚轮缩放
- UI按钮切换材质
- 键盘快捷键

---

## 5. 材质系统

预置5种材质：
1. 默认白色
2. 炫酷黑色
3. 科技蓝色
4. 活力橙色
5. 奢华金色

---

*文档版本: v1.0.0*  
*最后更新: 2026-03-17*
