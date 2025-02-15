# 贡献指南 (Contributing Guide)

**欢迎参与本项目！以下是贡献代码的流程和规范。**

## 第一步：开始贡献

### 1. Fork 仓库

- 点击 GitHub 右上角的 **Fork** 按钮，将仓库复制到你的账号下。

### 2. 克隆仓库到本地

```bash
git clone https://github.com/你的用户名/Hello-CPP.git
cd Hello-CPP
```

### 3. 添加上游远程仓库

```bash
git remote add upstream https://github.com/Evilrabbit520/Hello-CPP.git
```

## 第二步：开发流程

### **1. 本项目始终基于 `dev` 分支开发**（⚠️ 务必注意）

- **所有贡献必须基于最新的 `dev` 分支**：
- 
```bash
git fetch upstream dev   # 获取上游最新 dev 分支
git checkout -b 你的分支名 upstream/dev  # 基于上游 dev 创建新分支
```

### 2. 提交代码

- 提交信息需遵循 [Conventional Commits](https://www.conventionalcommits.org/) 规范  
  示例：`feat: 添加示例代码` 或 `fix: 修改了某个错别字`

### 3. 同步上游更新

- 开发过程中定期拉取上游 `dev` 分支的更新：

```bash
git fetch upstream dev
git rebase upstream/dev   # 推荐使用 rebase 保持提交历史线性
```

## 第三步：提交 Pull Request (PR)

### 1. 推送到你的 Fork

```bash
git push origin 你的分支名
```

### 2. 发起 PR

- 在 GitHub 上选择 **Compare across forks**  
  - **目标仓库**: 原始仓库 (`原始仓库作者/项目名`)  
  - **目标分支**: `dev`（**请勿选择 main 分支**）

### 3. PR 描述规范
- 标题：简明描述修改内容（如：`feat: 添加了示例代码`）  
- 内容：  
  - 说明修改的问题或新增的内容  
  - 关键代码片段或截图（如有必要）  
  - 关联的 Issue 编号（如：`Closes #123`）

## 代码规范

### 1. 代码风格

- 遵循项目现有的写作风格（缩进、命名等）  
- 新增代码需包含单元测试（如适用）

### 2. 静态检查

- 提交前运行项目要求的检查工具

## 其他说明

- 请保持提交历史清晰（避免无意义的合并提交）  
- 若 PR 涉及重大变更，请先创建 Issue 讨论  
- 维护者将在 3 个工作日内审核你的 PR

---

**感谢你的贡献！** 🌟