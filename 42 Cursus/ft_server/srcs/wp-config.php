<?php
/**
 * La configuration de base de votre installation WordPress.
 *
 * Ce fichier contient les réglages de configuration suivants : réglages MySQL,
 * préfixe de table, clés secrètes, langue utilisée, et ABSPATH.
 * Vous pouvez en savoir plus à leur sujet en allant sur
 * {@link http://codex.wordpress.org/fr:Modifier_wp-config.php Modifier
 * wp-config.php}. C’est votre hébergeur qui doit vous donner vos
 * codes MySQL.
 *
 * Ce fichier est utilisé par le script de création de wp-config.php pendant
 * le processus d’installation. Vous n’avez pas à utiliser le site web, vous
 * pouvez simplement renommer ce fichier en "wp-config.php" et remplir les
 * valeurs.
 *
 * @package WordPress
 */

// ** Réglages MySQL - Votre hébergeur doit vous fournir ces informations. ** //
/** Nom de la base de données de WordPress. */
define( 'DB_NAME', 'wpdb' );

/** Utilisateur de la base de données MySQL. */
define( 'DB_USER', 'admin' );

/** Mot de passe de la base de données MySQL. */
define( 'DB_PASSWORD', '1234' );

/** Adresse de l’hébergement MySQL. */
define( 'DB_HOST', 'localhost' );

/** Jeu de caractères à utiliser par la base de données lors de la création des tables. */
define( 'DB_CHARSET', 'utf8mb4' );

/** Type de collation de la base de données.
  * N’y touchez que si vous savez ce que vous faites.
  */
define('DB_COLLATE', '');

/**#@+
 * Clés uniques d’authentification et salage.
 *
 * Remplacez les valeurs par défaut par des phrases uniques !
 * Vous pouvez générer des phrases aléatoires en utilisant
 * {@link https://api.wordpress.org/secret-key/1.1/salt/ le service de clefs secrètes de WordPress.org}.
 * Vous pouvez modifier ces phrases à n’importe quel moment, afin d’invalider tous les cookies existants.
 * Cela forcera également tous les utilisateurs à se reconnecter.
 *
 * @since 2.6.0
 */
define( 'AUTH_KEY',         '1$~jDrOlb31t)g[/6c+Krlnv2E%> #UQ&/!h0Jp~4-k:Kpm3x(}d  (KW,q*b`F$' );
define( 'SECURE_AUTH_KEY',  'OH_/VfzKuB b <}mag0(O(H?mC;4@IU+kiY:B!,RwKa!3J4mJ&t`R)&KH(Mf}HGE' );
define( 'LOGGED_IN_KEY',    '0bi}/<P]a(O[#7.e4Gv8NRpMcL?d.@MW;wnjC6-ei^A8-^7YP^t6{RIFfsRb59py' );
define( 'NONCE_KEY',        'A+Rmab;vk{~jB:LEg;vrnvdrI#IM2%Vzn$8hhW$6Z1Lg}Nc#r!jcu9cUK0b;6VKy' );
define( 'AUTH_SALT',        '.aOpf82kCKym:1zb0(YY&!*O[1FFZ0F*z#2h3oP):W<tyf%Z(;KQs*JkaiuUYtO;' );
define( 'SECURE_AUTH_SALT', 'yX V,mRN96?K]EsT= N)VGac]5Dpm}i/7aeHCQ~z7a+(L`*!#[ZxrLxdI W+/p@H' );
define( 'LOGGED_IN_SALT',   '#zcT$LurX+2eqv#bsMB{B!}n%NfWos8$[f;@!nAr1%4ik6dmrI.;]Bl03LqF#-P2' );
define( 'NONCE_SALT',       '?)6k7 8N#]`+;h$0GvC*<#)u^~_3l{?!Aw[]r_&-C7v<Ed9hUn0G]kcbPhth.8Sl' );
/**#@-*/

/**
 * Préfixe de base de données pour les tables de WordPress.
 *
 * Vous pouvez installer plusieurs WordPress sur une seule base de données
 * si vous leur donnez chacune un préfixe unique.
 * N’utilisez que des chiffres, des lettres non-accentuées, et des caractères soulignés !
 */
$table_prefix = 'wp_';

/**
 * Pour les développeurs : le mode déboguage de WordPress.
 *
 * En passant la valeur suivante à "true", vous activez l’affichage des
 * notifications d’erreurs pendant vos essais.
 * Il est fortemment recommandé que les développeurs d’extensions et
 * de thèmes se servent de WP_DEBUG dans leur environnement de
 * développement.
 *
 * Pour plus d’information sur les autres constantes qui peuvent être utilisées
 * pour le déboguage, rendez-vous sur le Codex.
 *
 * @link https://codex.wordpress.org/Debugging_in_WordPress
 */
define('WP_DEBUG', false);

/* C’est tout, ne touchez pas à ce qui suit ! Bonne publication. */

/** Chemin absolu vers le dossier de WordPress. */
if ( !defined('ABSPATH') )
	define('ABSPATH', dirname(__FILE__) . '/');

/** Réglage des variables de WordPress et de ses fichiers inclus. */
require_once(ABSPATH . 'wp-settings.php');
