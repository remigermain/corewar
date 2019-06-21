.name "🍌🍍 Le Pet de Nonne arrangé 🍍🍌"

.comment " Il est également appelé « beignet de vent »"


vanille_banane:
	zjmp			%:piment_gingembre
	zjmp			%:piment_gingembre
	zjmp			%:piment_gingembre
	ld				%506,r2


ananas_coco:
	fork            %:piment_gingembre
	ld				%34144757,r4
	st				r4,r5
	ld				%67305472,r6
	ld				%262144,r9
	ld				%4,r1
	ld				%0,r16
	zjmp            %:boire_de_l_eau
	live			%3134197165
	live			%3134197165
	live			%3134197165
	zjmp            %:boire_de_l_eau
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165

piment_gingembre:
	ld				%190055681,r4
	ld				%190055937,r5
	ld				%57673984,r6
	ld				%134443017,r9
	st				r1, 345
	ld				%0, r1

	zjmp			%:boire_de_l_eau
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	live			%3134197165
	aff				r2

boire_de_l_eau:
	st		r1, -333
	sti		r4,r1,%505
	live 	%42
	zjmp	%494
