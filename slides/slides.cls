% common style file for the slides

\ProvidesClass{slides}

\makeatletter

\newcommand{\my@theme}{TalkICP2012}
\DeclareOption{frameless}{%
  \renewcommand{\my@theme}{FramelessTalkICP2012}%
  \PassOptionsToClass{12pt}{beamer}
}
\DeclareOption*{\PassOptionsToClass{\CurrentOption}{beamer}}

\PassOptionsToClass{t}{beamer}

\ProcessOptions

\LoadClass{beamer}

\usetheme{\my@theme}

\makeatother

\RequirePackage[utf8]{inputenc}
\RequirePackage[T1]{fontenc}
\RequirePackage{beamerextensions}
\RequirePackage{listings}

\hypersetup{
  pdfpagelabels=off,
  linkcolor=black,
  citecolor=black,
  filecolor=black,
  urlcolor=black
}

% no navigation for Axel, keyboard rulez!
\beamertemplatenavigationsymbolsempty

\graphicspath{{figures/}}

\hbadness=10000
\sloppy

% bold true type
\DeclareFontShape{OT1}{cmtt}{bx}{n}{
  <5><6><7><8><9><10><10.95><12><14.4><17.28><20.74><24.88>cmttb10}{}

% the default font for listings needs to be the ttdefault, otherwise
% all special characters are messed up and you cannot copy&paste out
% of the code.
\renewcommand{\ttdefault}{fvm}

% increase size of the tiny font
\renewcommand{\tiny}{\fontsize{7}{8}\selectfont}

\lstset{
  frame=tb,
  language=Python,
  aboveskip=0.2em,
  belowskip=0.2em,
  showstringspaces=false,
  basicstyle={\ttfamily\footnotesize},
  keywordstyle={\bfseries},
  commentstyle={\color{red!80!black}},
  stringstyle={\fontfamily{cmtt}\selectfont},
  emphstyle={\usebeamercolor[fg]{alerted text}\bfseries},
  emphstyle={[2]\usebeamercolor[fg]{alerted text}},
  basewidth={0.55em},
  escapechar=@
}
\lstdefinestyle{inline}{columns=fullflexible}
\lstdefinestyle{unframed}{frame={},aboveskip=0.25em,belowskip=0.25em}
\lstdefinestyle{output}{frame=single,backgroundcolor=\color{CDblue4},xleftmargin=2em,xrightmargin=0.3333em}

% to manually set listings-like, e.g. for highlighting
\newcommand{\lststringstyle}[1]{\fontfamily{cmtt}\selectfont{}#1}
\newcommand{\lstkeywordstyle}[1]{\bfseries{}#1}
\newcommand{\lstcommentstyle}[1]{\textcolor{red!80!black}{#1}}

\newcommand{\minisec}[1]{\alert{#1}}

\newenvironment{mytabular}[2]{%
  \renewcommand{\arraystretch}{1.1}%
  \setlength{\tabcolsep}{0.01\textwidth}%
  \begin{tabular}{#2}} {\end{tabular}}

\newcommand{\textrightarrow}{\ensuremath{\rightarrow}}

\newcommand{\densemath}{%
  \setlength{\abovedisplayskip}{0.3em}
  \setlength{\belowdisplayskip}{0.3em}}

% length to skip at the beginning of a block, if a itemize follows
% otherwise, the gap is optically too big.
\newlength{\biskip}
\setlength{\biskip}{-\topsep}
