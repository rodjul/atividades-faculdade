<?php
//conexao do bd
include "php/banco_conexao.php";
?>

<?php
$nome = $_POST['nome'];
$login = $_POST['login'];
$senha = $_POST['senha'];


$erro = 0;

?>

<?php
//validando cadastro

//para login empty($nome) || strstr($nome, ' '
if(empty($nome)==TRUE){
    echo "Insira um nome<br/>";
    echo "<br/><a href='index.html'>Voltar</a>";
    $erro = 1;
}

if(empty($login) || strstr($login,' ') ==TRUE){
    echo "Insira um login<br/>";
    echo "<br/><a href='index.html'>Voltar</a>";
    $erro = 1;
}
/*
if(strlen($email)< 3 || strstr($email, '@')==FALSE){
    echo "Insira o email corretamente <br/>";
    echo "<br/><a href='index.html'>Voltar</a>";
    $erro = 1;
}*/


if(empty($senha) || strlen($senha) < 3){
    echo "Insira uma senha maior que 3 caracteres<br/>";
    echo "<br/><a href='index.html'>Voltar</a>";
    $erro = 1;
}


if($erro==0){
    include "php/cadastro1.php";
}
?>



<?php
mysqli_close($conexao);
?>