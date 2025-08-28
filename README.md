<div align="center">

# No solve No life

![languages](https://img.shields.io/github/languages/count/TeamWon1/demo-repository)
![issues](https://img.shields.io/github/issues-pr/TeamWon1/demo-repository)
![commits](https://img.shields.io/github/commit-activity/m/TeamWon1/demo-repository)

알고리즘 풀이 레포

</div>

## Features

- [Problems](#Problems)
- [Introduction](#Introduction)
- [Rules](#Rules)
- [Schedule](#Schedule)

## Problems

<details>
  <summary>Click to expand!</summary>

### 250901

- [내려가기](https://www.acmicpc.net/problem/2096)
- [지름길](https://www.acmicpc.net/problem/1446)
- [퇴사](https://www.acmicpc.net/problem/1450)
- [동전 0](https://www.acmicpc.net/problem/11047)

<details>
  <summary>이전 주 문제들!</summary>

### 250818

- [회전 초밥](https://www.acmicpc.net/problem/2531)
- [테트로미노](https://www.acmicpc.net/problem/14500)
- [회의실 배정](https://www.acmicpc.net/problem/1931)
- [전화번호 목록](https://www.acmicpc.net/problem/5052)

### 250812

- [토마토](https://www.acmicpc.net/problem/7576)
- [두용액](https://www.acmicpc.net/problem/2470)
- [합분해](https://www.acmicpc.net/problem/2225)
- [연구소](https://www.acmicpc.net/problem/14502)

### 250805

- [효율적인 해킹](https://www.acmicpc.net/problem/1325)
- [정수삼각형](https://www.acmicpc.net/problem/1932)
- [Fly me to the Alpha Centauri](https://www.acmicpc.net/problem/1011)
- [01타일](https://www.acmicpc.net/problem/1904)

### 250729

- [ATM](https://www.acmicpc.net/problem/11399)
- [어린왕자](https://www.acmicpc.net/problem/1004)
- [DFS와 BFS](https://www.acmicpc.net/problem/1260)
- [두 수의 합](https://www.acmicpc.net/problem/3273)

### 250629

- [TEST](https://www.acmicpc.net/problem/17615)
- [TEST](https://www.acmicpc.net/problem/2096)
- [TEST](https://www.acmicpc.net/problem/20057)
- [TEST](https://www.acmicpc.net/problem/10942)
- [TEST](https://www.acmicpc.net/problem/15903)
</details>
</details>

## Introduction

문제 풀이를 위한 레포입니다. 매 주 몇 개의 문제 풀이를 진행하며 스터디 회의에서 각자 풀이법 등을 공유합니다. 소개나 요청을 통해 참석을 원하는 사람이 있다면 모든 스터디원이 동의할 경우 합류합니다.

## Rules

### Overall

최상위 디렉토리에 그룹원 각자의 디렉토리를 생성하여 구성합니다. 본인의 디렉토리엔 날짜를 명시한 디렉토리를 생성하여 관리하고, 매 스터디에 하나의 날짜 디렉토리를 업로드합니다. 업로드 내용으로는 각 문제의 코드 원문과 전체적인 코드 설명을 포함한 readme.md 파일이 있습니다.

### Code

해당 그룹에서는 언어의 제한을 두지 않습니다. C++이나 JS, Python 등 본인이 원하는 언어를 사용하여도 문제없습니다. 다만 다른 언어를 사용하는 그룹원이 이해할 수 있도록 설명 등을 포함하여 readme에 작성합니다. 코드의 원문의 첫 라인부터 해당 문제의 URL과 문제의 제목을 기입하여 코드 파일만을 가지고 어떤 문제인지 식별할 수 있도록 합니다.

### Branch

`feature/(내용)` 브랜치 이름을 통해 현재 브랜치가 문제풀이를 위한 브랜치임을 알 수 있도록 명시합니다. 간단한 수정이나 문제 링크 업로드를 위한 일시적인 브랜치의 경우 명명규칙을 따를 필요는 없으나, publish 이후 최대한 빠르게 PR을 진행 후 삭제함을 원칙으로 합니다.

### Commit

`(category) : (comments)` 의 구조를 따릅니다. category는 문제풀이를 위한 solve와 readme 작성을 위한 write로 나뉩니다. 한 주에 각 카테고리 하나씩 구성하는 것을 추천하지만, 문제를 나누어 푸는 등의 이유로 solve 카테고리를 나누는 것은 상관 없습니다. comments 부분엔 문제 번호 및 간단한 내용을 기입합니다. 문제풀이에 대해선 본인의 디렉토리 내의 파일만 변경하는 것을 원칙으로 하며, 그 외의 커밋에 대해서는 따로 커밋의 이름을 정하진 않습니다.

### Pull request & Merge

PR 제목에 상관없이 요청합니다. Merge는 지정된 Approve의 수를 만족해야 가능하도록 설정되어 있습니다.

### Meeting

매 주 특별한 일이 없다면 Google Meet을 통한 회의를 진행합니다. 발표 순서는 임의로 지정하여 진행하며 본인의 차례엔 문제의 풀이방법이나 학습했던 특별한 내용에 대해 설명합니다. 발표가 모두 끝난 뒤엔 다음 회의까지의 문제 선정작업을 진행합니다. 백준이나 SW Academy, Programmers의 문제를 가지고 선정을 진행하며, 일반적으로 문제의 카테고리를 미리 확인하지 않고 가져옵니다. **다른이의 문제 풀이를 읽는 것은 미팅단계 이전에 선행되며, 미팅 시간에는 문제풀이의 핵심 등의 설명이나 코드에 대한 질문을 주로 다룹니다.**

## Schedule

- 현재 회의는 매주**?요일 ?오후 시** 입니다. (팀원과의 스케줄 조정으로 요일은 바뀔 수 있습니다)
- 회의날 오전 8시까지 문제 풀이 내용을 모두 정리해서 PR을 진행합니다.
- 회의 시간 이전까지 모든 이의 코드를 읽고 리뷰를 진행합니다. Approve를 포함합니다.
- 회의 시간 직전 본인의 PR에 들어온 Comment 들을 파악합니다. 질문 등에 대해선 회의 이전 답을 생각해봅니다.
- 회의를 시작하면 각자 돌아가며 코드 설명을 진행합니다.
