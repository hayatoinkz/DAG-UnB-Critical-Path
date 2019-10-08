graph
[

  node
  [
    id 113034 CÁLCULO1 6
  ]
  node
  [
    id 113468 INTRODSISTEMASCOMPUTACIONAIS 4
  ]
  node
  [
    id 113476 ALGORITMOSPROGRCOMPUTADORES 6
  ]
  node
  [
	  id 116726 INFORMATICAESOCIEDADE 2
  ]

  node
  [
    id 113450 FUNDAMENTOSTEÓRDACOMPUTAÇÃO 4
  ]
  node
  [
	  id 129011 CIRCUITOSLÓGICOS 4
  ]
  node
  [
	  id 116319 ESTRUTURASDEDADOS 4
  ]
  node
  [
	  id 129020 LABORATÓRIOCIRCUITOSLÓGICOS 2
  ]
  node
  [
	  id 113042 CÁLCULO2 6
  ]
  node
  [
	  id 113093 INTRODUCAOAALGEBRALINEAR 4
  ]
  
  node
  [
	  id 116394 ORGARQDECOMPUTADORES 4
  ]
  node
  [
	  id 117889 TECNICASDEPROGRAMAÇÃO1 4
  ]
  node
  [
	  id 113107 ALGEBRA1 4
  ]
  node
  [
	  id 113417 CALCULONUMERICO 4
  ]
  node
  [
	  id 115045 PROBABILIDADEEESTATÍSTICA 4
  ]
  
  node
  [
	  id 117366 LÓGICACOMPUTACIONAL1 4
  ]
  node
  [
	  id 117897 TECNICASDEPROGRAMAÇÃO2 4
  ]
  node
  [
	  id 117901 TEORIAEAPLICAÇÃODEGRAFOS 4
  ]
  node
  [
	  id 116572 REDESDECOMPUTADORES 4
  ]
  
  node
  [
	  id 116343 LINGUAGENSDEPROGRAMACAO 4
  ]
  node
  [
	  id 117935 PROGRAMAÇÃOCONCORRENTE 4
  ]

  node
  [
	  id 116441 ENGENHARIADESOFTWARE 4
  ]

  node
  [
	  id 116378 BANCOSDEDADOS 4
  ]

  node
  [
	  id 116653 INTROINTELIGENCIAARTIFICIAL 4
  ]

  node
  [
	  id 116432 SOFTWAREBASICO 4
  ]
  node
  [
	  id 117960 FUNDAMENTOSSISTOPERACIONAIS 4
  ]
  node
  [
	  id 116882 AUTÔMATOSECOMPUTABILIDADE 6
  ]
  node
  [
	  id 116416 SISTEMASDEINFORMACAO 4
  ]
  node
  [
	  id 117943 COMPUTAÇÃOEXPERIMENTAL 4
  ]

  node
  [
	  id 117536 PROJETOANÁLISEDEALGORITMOS 4
  ]
  node
  [
	  id 117951 COMPILADORES 4
  ]
  node
  [
	  id 117927 SEGURANÇACOMPUTACIONAL 4
  ]
  
  node
  [
    id 117919 METODOLOGIACIENTIFICA 2
  ]
  
  node
  [
    id 116297 TAVANCADOSEMCOMPUTADORES 4
  ]

  edge
  [
    comment "APC=>CL"
    source 113476
    target 129011
  ]
  edge
  [
    comment "APC=>LCL"
    source 113476
    target 129020
  ]
  edge
  [
    comment "APC=>ED"
    source 113476
    target 116319
  ]
  edge
  [
    comment "C1=>C2"
    source 113034
    target 113042
  ]
  edge
  [
    comment "C1=>PE"
    source 113034
    target 115045
  ]
  edge
  [
    comment "CL=>OAC"
    source 129011
    target 116394
  ]
  edge
  [
    comment "LCL=>OAC"
    source 129020
    target 116394
  ]
  edge
  [
    comment "ED=>TP1"
    source 116319
    target 117889
  ]
  edge
  [
    comment "C2=>CN"
    source 113042
    target 113417
  ]
  edge
  [
    comment "ED=>LC1"
    source 116319
    target 117366
  ]
  edge
  [
    comment "ED=>TAG"
    source 116319
    target 117901
  ]
  edge
  [
    comment "ED=>REDES"
    source 116319
    target 116572
  ]
  edge
  [
    comment "ED=>LP"
    source 116319
    target 116343
  ]
  edge
  [
    comment "ED=>SI"
    source 116319
    target 116416
  ]
  edge
  [
    comment "ED=>BD"
    source 116319
    target 116378
  ]
  edge
  [
    comment "ED=>IIA"
    source 116319
    target 116653
  ]
  edge
  [
    comment "TP1=>TP2"
    source 117889
    target 117897
  ]
  edge
  [
    comment "TP1=>ENG_SOFT"
    source 117889
    target 116441
  ]
  edge
  [
    comment "TP2=>PC"
    source 117897
    target 117935
  ]
  edge
  [
    comment "OAC=>PC"
    source 116394
    target 117935
  ]
  edge
  [
    comment "OAC=>SB"
    source 116394
    target 116432
  ]
  edge
  [
    comment "ED=>SB"
    source 116319
    target 116432
  ]
  edge
  [
    comment "PC=>FSO"
    source 117935
    target 117960
  ]
  edge
  [
    comment "A1=>AUTOMATOS"
    source 113107
    target 116882
  ]
  edge
  [
    comment "PE=>COMP_EXP"
    source 115045
    target 117943
  ]
  edge
  [
    comment "ED=>COMP_EXP"
    source 116319
    target 117943
  ]
  edge
  [
    comment "C1=>PROJ_ANALI_ALGORIT"
    source 113034
    target 117536
  ]
  edge
  [
    comment "ED=>PROJ_ANALI_ALGORIT"
    source 116319
    target 117536
  ]

  edge
  [
    comment "LP=>COMPILADORES"
    source 116343
    target 117951
  ]
  edge
  [
    comment "SB=>COMPILADORES"
    source 116432
    target 117951
  ]
  edge
  [
    comment "AUTOMATOS=>COMPILADORES"
    source 116882
    target 117951
  ]
  edge
  [
    comment "REDES=>SEGURANCA"
    source 116572
    target 117927
  ]
]