<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tutorat MPI - Mathématiques pour l'Informatique</title>
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700;800&display=swap');
        
        :root {
            --bg-primary: #0a0d1f;
            --bg-secondary: #111428;
            --card-primary: linear-gradient(135deg, rgba(20, 25, 45, 0.9), rgba(15, 18, 40, 0.95));
            --card-secondary: linear-gradient(135deg, rgba(25, 30, 55, 0.8), rgba(18, 22, 42, 0.9));
            --card-accent: linear-gradient(135deg, rgba(107, 138, 255, 0.15), rgba(156, 107, 255, 0.15));
            --text-primary: #f8fafc;
            --text-secondary: #cbd5e1;
            --text-muted: #94a3b8;
            --accent-primary: #6366f1;
            --accent-secondary: #8b5cf6;
            --accent-tertiary: #06b6d4;
            --accent-gradient: linear-gradient(135deg, #6366f1, #8b5cf6);
            --accent-gradient-alt: linear-gradient(135deg, #06b6d4, #3b82f6);
            --border-subtle: rgba(148, 163, 184, 0.1);
            --border-accent: rgba(99, 102, 241, 0.3);
            --shadow-sm: 0 2px 8px rgba(0, 0, 0, 0.1);
            --shadow-md: 0 8px 32px rgba(0, 0, 0, 0.2);
            --shadow-lg: 0 24px 64px rgba(0, 0, 0, 0.4);
            --shadow-accent: 0 8px 32px rgba(99, 102, 241, 0.2);
            --radius-sm: 8px;
            --radius-md: 16px;
            --radius-lg: 24px;
            --transition: all 0.3s cubic-bezier(0.4, 0, 0.2, 1);
            --bounce: cubic-bezier(0.68, -0.55, 0.265, 1.55);
        }

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
        }

        html {
            scroll-behavior: smooth;
        }

        body {
            font-family: 'Inter', ui-sans-serif, system-ui, -apple-system, sans-serif;
            background: radial-gradient(1400px 800px at 70% -5%, rgba(99, 102, 241, 0.15), transparent 70%),
                       radial-gradient(1200px 600px at -10% 20%, rgba(139, 92, 246, 0.12), transparent 60%),
                       radial-gradient(800px 400px at 90% 80%, rgba(6, 182, 212, 0.08), transparent 50%),
                       var(--bg-primary);
            color: var(--text-primary);
            line-height: 1.6;
            min-height: 100vh;
            overflow-x: hidden;
        }

        .container {
            max-width: 1200px;
            margin: 0 auto;
            padding: 2rem;
        }

        /* HERO SECTION */
        .hero {
            display: grid;
            grid-template-columns: 1.2fr 0.8fr;
            gap: 3rem;
            align-items: center;
            margin-bottom: 4rem;
            min-height: 70vh;
            position: relative;
        }

        .hero::before {
            content: '';
            position: absolute;
            top: -20%;
            right: -20%;
            width: 40%;
            height: 140%;
            background: radial-gradient(circle, rgba(99, 102, 241, 0.1), transparent 70%);
            border-radius: 50%;
            animation: float 20s ease-in-out infinite;
            z-index: -1;
        }

        @keyframes float {
            0%, 100% { transform: translateY(0px) rotate(0deg); }
            50% { transform: translateY(-20px) rotate(2deg); }
        }

        .hero-content {
            z-index: 2;
        }

        .badge {
            display: inline-flex;
            align-items: center;
            gap: 0.75rem;
            background: var(--accent-gradient);
            padding: 0.75rem 1.5rem;
            border-radius: 999px;
            font-weight: 600;
            font-size: 0.95rem;
            box-shadow: var(--shadow-accent);
            margin-bottom: 1.5rem;
            animation: slideInUp 0.8s var(--bounce);
        }

        .title {
            font-size: clamp(2.5rem, 5vw, 4rem);
            font-weight: 800;
            line-height: 1.1;
            margin-bottom: 1rem;
            background: linear-gradient(135deg, var(--text-primary), var(--text-secondary));
            -webkit-background-clip: text;
            -webkit-text-fill-color: transparent;
            background-clip: text;
            animation: slideInUp 0.8s var(--bounce) 0.1s both;
        }

        .subtitle {
            font-size: 1.25rem;
            color: var(--text-muted);
            margin-bottom: 2rem;
            animation: slideInUp 0.8s var(--bounce) 0.2s both;
        }

        .cta-buttons {
            display: flex;
            flex-wrap: wrap;
            gap: 1rem;
            animation: slideInUp 0.8s var(--bounce) 0.3s both;
        }

        .btn {
            display: inline-flex;
            align-items: center;
            gap: 0.75rem;
            padding: 1rem 1.5rem;
            border-radius: var(--radius-md);
            text-decoration: none;
            color: var(--text-primary);
            font-weight: 600;
            transition: var(--transition);
            position: relative;
            overflow: hidden;
        }

        .btn-primary {
            background: var(--accent-gradient);
            box-shadow: var(--shadow-accent);
        }

        .btn-secondary {
            background: var(--card-primary);
            border: 1px solid var(--border-accent);
            backdrop-filter: blur(10px);
        }

        .btn::before {
            content: '';
            position: absolute;
            inset: 0;
            background: linear-gradient(135deg, rgba(255, 255, 255, 0.2), transparent);
            opacity: 0;
            transition: var(--transition);
        }

        .btn:hover {
            transform: translateY(-2px);
            box-shadow: 0 16px 48px rgba(99, 102, 241, 0.3);
        }

        .btn:hover::before {
            opacity: 1;
        }

        .btn-mini {
            font-size: 0.85rem;
            color: var(--text-muted);
            font-weight: 500;
        }

        /* HERO CARD */
        .hero-card {
            background: var(--card-primary);
            border: 1px solid var(--border-accent);
            border-radius: var(--radius-lg);
            padding: 2rem;
            box-shadow: var(--shadow-lg);
            backdrop-filter: blur(20px);
            animation: slideInRight 0.8s var(--bounce) 0.4s both;
            position: relative;
            overflow: hidden;
        }

        .hero-card::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            right: 0;
            height: 1px;
            background: var(--accent-gradient);
            opacity: 0.6;
        }

        .hero-card h3 {
            font-size: 1.5rem;
            font-weight: 700;
            margin-bottom: 1rem;
            color: var(--text-primary);
        }

        .hero-card p {
            color: var(--text-secondary);
            margin-bottom: 1.5rem;
            line-height: 1.7;
        }

        .info-grid {
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 1rem;
        }

        .info-item {
            padding: 0.75rem;
            background: rgba(99, 102, 241, 0.1);
            border-radius: var(--radius-sm);
            border: 1px solid var(--border-accent);
        }

        .info-label {
            font-size: 0.85rem;
            color: var(--text-muted);
            font-weight: 500;
            text-transform: uppercase;
            letter-spacing: 0.05em;
        }

        .info-value {
            font-weight: 700;
            color: var(--text-primary);
            margin-top: 0.25rem;
        }

        /* SECTIONS */
        .section {
            margin-bottom: 4rem;
        }

        .section-grid {
            display: grid;
            gap: 2rem;
        }

        .grid-2-1 {
            grid-template-columns: 2fr 1fr;
        }

        .grid-1-2 {
            grid-template-columns: 1fr 2fr;
        }

        .grid-1 {
            grid-template-columns: 1fr;
        }

        .card {
            background: var(--card-secondary);
            border: 1px solid var(--border-subtle);
            border-radius: var(--radius-lg);
            padding: 2rem;
            box-shadow: var(--shadow-md);
            backdrop-filter: blur(10px);
            transition: var(--transition);
            position: relative;
            overflow: hidden;
        }

        .card::before {
            content: '';
            position: absolute;
            top: 0;
            left: 0;
            right: 0;
            height: 2px;
            background: var(--accent-gradient-alt);
            transform: scaleX(0);
            transition: var(--transition);
            transform-origin: left;
        }

        .card:hover {
            transform: translateY(-4px);
            box-shadow: var(--shadow-lg);
            border-color: var(--border-accent);
        }

        .card:hover::before {
            transform: scaleX(1);
        }

        .card h3 {
            font-size: 1.5rem;
            font-weight: 700;
            margin-bottom: 1.5rem;
            display: flex;
            align-items: center;
            gap: 0.75rem;
            color: var(--text-primary);
        }

        .card-accent {
            background: var(--card-accent);
            border: 1px solid var(--border-accent);
        }

        /* LISTS */
        .feature-list {
            list-style: none;
            display: grid;
            gap: 1rem;
        }

        .feature-item {
            display: flex;
            align-items: flex-start;
            gap: 1rem;
            padding: 1rem;
            border-radius: var(--radius-sm);
            transition: var(--transition);
        }

        .feature-item:hover {
            background: rgba(99, 102, 241, 0.05);
            transform: translateX(4px);
        }

        .feature-dot {
            width: 12px;
            height: 12px;
            border-radius: 50%;
            background: var(--accent-gradient);
            margin-top: 0.5rem;
            flex-shrink: 0;
            box-shadow: 0 0 20px rgba(99, 102, 241, 0.4);
        }

        .feature-content {
            flex: 1;
        }

        .feature-content strong {
            color: var(--accent-primary);
            font-weight: 600;
        }

        /* TAGS */
        .tag-container {
            display: flex;
            flex-wrap: wrap;
            gap: 0.75rem;
            margin-top: 1rem;
        }

        .tag {
            padding: 0.5rem 1rem;
            background: rgba(99, 102, 241, 0.1);
            border: 1px solid var(--border-accent);
            border-radius: 999px;
            font-size: 0.9rem;
            font-weight: 500;
            color: var(--text-secondary);
            transition: var(--transition);
        }

        .tag:hover {
            background: rgba(99, 102, 241, 0.2);
            transform: translateY(-2px);
            box-shadow: 0 4px 16px rgba(99, 102, 241, 0.2);
        }

        /* PROGRESS INDICATOR */
        .progress-indicator {
            position: fixed;
            top: 0;
            left: 0;
            width: 100%;
            height: 3px;
            background: rgba(99, 102, 241, 0.1);
            z-index: 1000;
        }

        .progress-bar {
            height: 100%;
            background: var(--accent-gradient);
            width: 0%;
            transition: width 0.3s ease;
        }

        /* ANIMATIONS */
        @keyframes slideInUp {
            from {
                opacity: 0;
                transform: translateY(30px);
            }
            to {
                opacity: 1;
                transform: translateY(0);
            }
        }

        @keyframes slideInRight {
            from {
                opacity: 0;
                transform: translateX(30px);
            }
            to {
                opacity: 1;
                transform: translateX(0);
            }
        }

        .animate-on-scroll {
            opacity: 0;
            transform: translateY(30px);
            transition: all 0.8s var(--bounce);
        }

        .animate-on-scroll.visible {
            opacity: 1;
            transform: translateY(0);
        }

        /* RESPONSIVE */
        @media (max-width: 768px) {
            .container {
                padding: 1rem;
            }

            .hero {
                grid-template-columns: 1fr;
                gap: 2rem;
                min-height: auto;
            }

            .section-grid {
                grid-template-columns: 1fr !important;
            }

            .cta-buttons {
                flex-direction: column;
            }

            .info-grid {
                grid-template-columns: 1fr;
            }

            .title {
                font-size: 2.5rem;
            }

            .card {
                padding: 1.5rem;
            }
        }

        /* INTERACTIVE ELEMENTS */
        .interactive-demo {
            margin-top: 1rem;
            padding: 1rem;
            background: rgba(6, 182, 212, 0.1);
            border: 1px solid rgba(6, 182, 212, 0.3);
            border-radius: var(--radius-sm);
            cursor: pointer;
            transition: var(--transition);
        }

        .interactive-demo:hover {
            background: rgba(6, 182, 212, 0.15);
            transform: scale(1.02);
        }

        .demo-text {
            font-size: 0.9rem;
            color: var(--accent-tertiary);
            font-weight: 600;
        }
    </style>
</head>
<body>
    <div class="progress-indicator">
        <div class="progress-bar" id="progressBar"></div>
    </div>

    <div class="container">
        <!-- HERO SECTION -->
        <section class="hero">
            <div class="hero-content">
                <div class="badge">
                    📘 Cours — MPI : Mathématiques pour l'Informatique
                </div>
                <h1 class="title">Bienvenue au tutorat MPI</h1>
                <p class="subtitle">Relations binaires • Graphes • Algèbre de Boole • Logique • Codage & théorie de l'information</p>
                <div class="cta-buttons">
                    <a class="btn btn-primary" href="#objectifs">
                        🎯 Objectifs
                        <span class="btn-mini">— ce que tu vas maîtriser</span>
                    </a>
                    <a class="btn btn-secondary" href="#tutorat">
                        🧭 Organisation
                        <span class="btn-mini">— déroulé des séances</span>
                    </a>
                    <a class="btn btn-secondary" href="#programme">
                        📚 Programme
                        <span class="btn-mini">— aperçu des thèmes</span>
                    </a>
                </div>
            </div>

            <div class="hero-card">
                <h3>À qui s'adresse ce tutorat ?</h3>
                <p>Étudiants en informatique, mathématiques appliquées, ou toute personne voulant des bases formelles solides pour modéliser, raisonner et coder.</p>
                <div class="info-grid">
                    <div class="info-item">
                        <div class="info-label">Niveau</div>
                        <div class="info-value">L1–L2 (débutant/interop)</div>
                    </div>
                    <div class="info-item">
                        <div class="info-label">Format</div>
                        <div class="info-value">Présentiel + exercices guidés</div>
                    </div>
                    <div class="info-item">
                        <div class="info-label">Rythme</div>
                        <div class="info-value">1–2h / semaine</div>
                    </div>
                    <div class="info-item">
                        <div class="info-label">Prérequis</div>
                        <div class="info-value">Algèbre & logique de base</div>
                    </div>
                </div>
                <div class="interactive-demo" onclick="showDemo()">
                    <div class="demo-text">✨ Cliquez pour voir un exemple interactif</div>
                </div>
            </div>
        </section>

        <!-- OBJECTIFS SECTION -->
        <section id="objectifs" class="section">
            <div class="section-grid grid-2-1">
                <div class="card animate-on-scroll">
                    <h3>🎯 Objectifs pédagogiques</h3>
                    <ul class="feature-list">
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Relations binaires</strong> : réflexivité, symétrie, transitivité, préordres, équivalences et partitions.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Graphes</strong> : terminologie, BFS/DFS, connexité, arbres, applications en algorithmique.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Algèbre de Boole</strong> : tables de vérité, DNF/CNF, simplification, circuits logiques.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Logique</strong> : propositions, prédicats, preuves (contradiction, contraposée), calcul booléen.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Codage</strong> : binaire, détection/correction (parité, Hamming), intro entropie.
                            </div>
                        </li>
                    </ul>
                </div>

                <div class="card card-accent animate-on-scroll">
                    <h3>🧰 Compétences clés</h3>
                    <p style="color: var(--text-secondary); margin-bottom: 1.5rem;">Développez votre expertise avec ces compétences fondamentales :</p>
                    <div class="tag-container">
                        <span class="tag">Raisonnement formel</span>
                        <span class="tag">Graphes</span>
                        <span class="tag">Circuits logiques</span>
                        <span class="tag">Modélisation</span>
                        <span class="tag">Preuves</span>
                        <span class="tag">Problèmes</span>
                        <span class="tag">Algorithmique</span>
                        <span class="tag">Structures</span>
                    </div>
                </div>
            </div>
        </section>

        <!-- TUTORAT SECTION -->
        <section id="tutorat" class="section">
            <div class="section-grid grid-1-2">
                <div class="card animate-on-scroll">
                    <h3>🧭 Déroulé des séances</h3>
                    <ul class="feature-list">
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Rappels ciblés</strong> & points délicats identifiés ensemble.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Exercices guidés</strong> & correction collaborative en temps réel.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Méthodes de preuve</strong> & rédaction rigoureuse pas à pas.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Q&A personnalisé</strong> selon vos besoins spécifiques.
                            </div>
                        </li>
                    </ul>
                </div>

                <div class="card animate-on-scroll">
                    <h3>🗂️ Méthode & ressources</h3>
                    <ul class="feature-list">
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Feuilles d'exercices progressives</strong> (⭐ à ⭐⭐⭐) avec solutions détaillées.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Mini-projets pratiques</strong> : <em>simplifieur booléen</em>, <em>parcours de graphes</em>, <em>simulateur Hamming</em>.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Fiches mémo interactives</strong> : relations, équivalences de formules, invariants de graphes.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>Conseils d'évaluation</strong> : structurer une preuve, justifier chaque étape méthodiquement.
                            </div>
                        </li>
                    </ul>
                </div>
            </div>
        </section>

        <!-- PROGRAMME SECTION -->
        <section id="programme" class="section">
            <div class="section-grid grid-1">
                <div class="card animate-on-scroll">
                    <h3>📚 Programme détaillé — 10 séances</h3>
                    <ul class="feature-list">
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>S1–S2 : Relations & Applications</strong> — Relations d'équivalence, classes d'équivalence, partitions, applications injectives/surjectives.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>S3–S4 : Théorie des Graphes</strong> — Parcours BFS/DFS, arbres couvrants, distances, ordonnancements topologiques.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>S5–S6 : Logique Formelle</strong> — Propositions, prédicats, quantificateurs, techniques de preuves (contradiction, contraposée).
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>S7–S8 : Algèbre de Boole</strong> — Tables de vérité, formes normales DNF/CNF, simplification, conception de circuits.
                            </div>
                        </li>
                        <li class="feature-item">
                            <div class="feature-dot"></div>
                            <div class="feature-content">
                                <strong>S9–S10 : Codage & Information</strong> — Représentations binaires, codes correcteurs (parité, Hamming), introduction à l'entropie.
                            </div>
                        </li>
                    </ul>
                    <div style="margin-top: 2rem; padding: 1.5rem; background: rgba(99, 102, 241, 0.08); border-radius: var(--radius-md); border: 1px solid var(--border-accent);">
                        <h4 style="color: var(--accent-primary); margin-bottom: 1rem;">🎯 Évaluation continue</h4>
                        <p style="color: var(--text-secondary);">Contrôles de connaissances, projets pratiques et évaluation par les pairs pour assurer une progression optimale.</p>
                    </div>
                </div>
            </div>
        </section>

        <!-- CONTACT/ACTION FINALE -->
        <section class="section">
            <div class="card card-accent animate-on-scroll" style="text-align: center; padding: 3rem 2rem;">
                <h3>🚀 Prêt à commencer ?</h3>
                <p style="font-size: 1.1rem; color: var(--text-secondary); margin-bottom: 2rem;">
                    Rejoignez le tutorat MPI et développez des compétences solides en mathématiques pour l'informatique !
                </p>
                <div style="display: flex; justify-content: center; gap: 1rem; flex-wrap: wrap;">
                    <a class="btn btn-primary" href="mailto:contact@example.com">
                        📧 S'inscrire maintenant
                    </a>
                    <a class="btn btn-secondary" href="#hero">
                        📋 Plus d'informations
                    </a>
                </div>
            </div>
        </section>
    </div>

    <script>
        // Progress bar
        function updateProgressBar() {
            const scrollTop = window.pageYOffset;
            const docHeight = document.body.scrollHeight - window.innerHeight;
            const scrollPercent = (scrollTop / docHeight) * 100;
            document.getElementById('progressBar').style.width = scrollPercent + '%';
        }

        // Scroll animations
        function handleScrollAnimations() {
            const elements = document.querySelectorAll('.animate-on-scroll');
            elements.forEach(el => {
                const elementTop = el.getBoundingClientRect().top;
                const elementVisible = 150;
                if (elementTop < window.innerHeight - elementVisible) {
                    el.classList.add('visible');
                }
            });
        }

        // Smooth scroll for anchor links
        function initSmoothScroll() {
            document.querySelectorAll('a[href^="#"]').forEach(anchor => {
                anchor.addEventListener('click', function(e) {
                    e.preventDefault();
                    const target = document.querySelector(this.getAttribute('href'));
                    if (target) {
                        target.scrollIntoView({
                            behavior: 'smooth',
                            block: 'start'
                        });
                    }
                });
            });
        }

        // Interactive demo function
        function showDemo() {
            const demo = document.querySelector('.interactive-demo');
            demo.style.background = 'linear-gradient(135deg, rgba(6, 182, 212, 0.2), rgba(99, 102, 241, 0.2))';
            demo.innerHTML = '<div class="demo-text">🎉 Génial ! Vous découvrirez plein d\'exemples comme celui-ci pendant le tutorat !</div>';
            
            setTimeout(() => {
                demo.style.background = 'rgba(6, 182, 212, 0.1)';
                demo.innerHTML = '<div class="demo-text">✨ Cliquez pour voir un exemple interactif</div>';
            }, 3000);
        </script>
    </body>
</html>
